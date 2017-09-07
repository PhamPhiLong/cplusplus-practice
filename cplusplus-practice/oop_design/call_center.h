//
// Created by Pham Phi Long on 5/31/2017.
//

#ifndef CPLUSPLUS_PRACTICE_CALL_CENTER_H
#define CPLUSPLUS_PRACTICE_CALL_CENTER_H

#include <memory>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

namespace {
    using namespace std;

    class Call {
    public:
        explicit Call(const int call_level) : call_level{call_level} {}

        int getLevel() {
            return call_level;
        }

    private:
        const int call_level;
    };

    class Employee {
    public:
        bool receiveCall(Call& call) {
            if (free && call.getLevel() <= employee_level) {
                free = false;
                processCall(call);
                return true;
            }

            return false;
        }

        void endCall() {
            free = true;
        }

    protected:
        virtual void processCall(const Call& call) = 0;

        explicit Employee(const int employee_level) : employee_level{employee_level} {}

        bool free{true};
        const int employee_level;
    };

    class Respondent : public Employee {
    public:
        Respondent() : Employee{0} {}

    private:
        void processCall(const Call& call) override {
            cout << "Respondent" << endl;
        }
    };

    class Manager : public Employee {
    public:
        Manager() : Employee{1} {}

    private:
        void processCall(const Call& call) override {
            cout << "Manager" << endl;
        }
    };

    class Director : public Employee {
    public:
        Director() : Employee{2} {}

    private:
        void processCall(const Call& call) override {
            cout << "Director" << endl;
        }
    };


    class CallCenter {
    public:
        static CallCenter& getInstance() {
            static CallCenter instance;
            return instance;
        }

        void receiveCall(Call& call) {
            bool can_handle{false};

            for (auto& employee_level : employee_queue) {
                for (auto& employee : employee_level) {
                    if (employee->receiveCall(call)) {
                        call_in_process[&call] = employee.get();
                        return;
                    }
                }
            }

            call_queue.push(&call);
        }

        void endCall(Call& call) {
            auto it = call_in_process.find(&call);
            if (it == call_in_process.end()) return;
            it->second->endCall();
            call_in_process.erase(it);
            if (!call_queue.empty()) {
                auto waiting_call = call_queue.front();
                receiveCall(*waiting_call);
            }
        }

    private:
        CallCenter() {
            employee_queue.emplace_back(10, make_shared<Respondent>());
            employee_queue.emplace_back(5, make_shared<Manager>());
            employee_queue.emplace_back(2, make_shared<Director>());
        }

        CallCenter(const CallCenter& callCenter) = delete;
        void operator=(const CallCenter&) = delete;
        CallCenter(CallCenter&& callCenter) = delete;
        void operator=(CallCenter&&) = delete;

        vector<vector<shared_ptr<Employee>>> employee_queue{};
        queue<Call*> call_queue{};
        unordered_map<Call*, Employee*> call_in_process{};
    };

    void run() {
        auto& call_center = CallCenter::getInstance();
        Call call1{1};
        call_center.receiveCall(call1);
    }
}
#endif //CPLUSPLUS_PRACTICE_CALL_CENTER_H

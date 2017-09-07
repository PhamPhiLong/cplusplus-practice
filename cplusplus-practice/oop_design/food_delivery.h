//
// Created by ASUS on 6/5/2017.
//

#ifndef CPLUSPLUS_PRACTICE_FOOD_DELIVERY_H
#define CPLUSPLUS_PRACTICE_FOOD_DELIVERY_H

//Design OO food delivery app catering to use cases -
//1) User can search different restaurant
//2) User can select a restaurant
//3) User sees a menu
//4) Restaurant can change the menu any time
//5) User adds an item from menu
//6) User orders the food
//7) User can track the order in real time
//8) User can cancel the order
//9) User pays for the order

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

namespace {
    class Menu {
    public:
        class Dish {
            string name;
            unsigned float price;
            string description;
        };

        unordere_map<>;
    };

    class Order {
    public:
        class Item {
            Menu::Dish& dish;

        };

        enum class Status {
            Ordering,
            Making,
            Delivering,
            Finished
        };
    };

    class Restaurant {
    public:
        string name;
        virtual const string& getName() const = 0;
        virtual Menu getMenu() = 0;
    };

    class FoodDeliverySystem {
    public:
        using date = string;

        vector<string> getRestaurantList() {
            vector<string> res_names{};
            for (auto restaurant : restaurant_list) {
                res_names.emplace_back(restaurant->getName());
            }
            return res_names;
        }



        vector<shared_ptr<Restaurant>> restaurant_list{};
        unordered_map<User, vector<Order>> order_database{};
    };

    class User {
    public:

    };
}
#endif //CPLUSPLUS_PRACTICE_FOOD_DELIVERY_H

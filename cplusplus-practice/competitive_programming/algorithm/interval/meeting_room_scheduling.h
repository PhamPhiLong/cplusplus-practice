//
// Created by Pham Phi Long on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_MEETING_ROOM_SCHEDULING_H
#define CPLUSPLUS_PRACTICE_MEETING_ROOM_SCHEDULING_H

// Given a list of meeting times, checks if any of them overlaps.
// The follow-up question is to return the minimum number of rooms
// required to accommodate all the meetings.
//
// Let’s start with an example. Suppose we use interval (start, end)
// to denote the start and end time of the meeting, we have the following meeting times:
// (1, 4), (5, 6), (8, 9), (2, 6).
// In the above example, apparently we should return true for the first question
// since (1, 4) and (2, 6) have overlaps.
// For the follow-up question, we need at least 2 meeting rooms so that
// (1, 4), (5, 6) will be put in one room and (2, 6), (8, 9) will be in the other.

#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

namespace {
    int find_max_room(const std::vector<std::pair<int, int>>& schedule) {
        std::vector<std::pair<int, char>> times;
        for (auto& meeting : schedule) {
            times.emplace_back(meeting.first, 'S');
            times.emplace_back(meeting.second, 'E');
        }

        std::sort(times.begin(),
                  times.end(),
                  [](const std::pair<int, char>& left, const std::pair<int, char>& right) {
                      return left.first < right.first;
                  }
        );

        int max_room{1};
        int cur_room{0};

        for (auto& time : times) {
            if(time.second == 'S') {
                ++cur_room;
                max_room = std::max(max_room, cur_room);
            }
            else --cur_room;
        }

        return max_room;
    }

    void run() {
        std::vector<std::pair<int, int>> schedule{{1, 4}, {3, 7}, {5, 6}, {8, 9}, {2, 6}, {3, 9}};
        std::cout << find_max_room(schedule) << std::endl;
    }
}

#endif //CPLUSPLUS_PRACTICE_MEETING_ROOM_SCHEDULING_H

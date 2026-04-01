// Complete Guide to C++ Programming Foundations
// Challenge 08_10
// Virtual Pet Schedule, by Eduardo Corpeño

#include <iostream>
#include <cstdint>
#include <vector>
#include <deque>
#include <string>
#include <utility>


template <typename T> using deque = std::deque<T>;
template <typename T> using vector = std::vector<T>;
template <typename T1, typename T2> using pair = std::pair<T1, T2>;
using string = std::string;

// Enum class for operations
enum class Operation{
    ADD_FRONT,
    ADD_BACK,
    REMOVE_FRONT,
    REMOVE_BACK
};

deque<pair<string, int>> ManagePetSchedule(const deque<pair<string, int>>& initialActivities, const vector<pair<Operation, pair<string, int>>>& operations){
    deque<pair<string, int>> schedule = initialActivities;

    for (const auto& action : operations){
        switch (action.first) {
            case Operation::ADD_FRONT:
                schedule.push_front(action.second);
                break;
            case Operation::ADD_BACK:
                schedule.push_back(action.second);
                break;
            case Operation::REMOVE_FRONT:
                if (!schedule.empty()){
                    schedule.pop_front();
                    break;
                }
            case Operation::REMOVE_BACK:
                if (!schedule.empty()){
                    schedule.pop_back();
                    break;
                }
        }
    }
    
    return schedule;
}

int main(){
    // Example 1
    deque<pair<string, int>> initialActivities = {{"Photograph",20},{"Play",45},{"Sleep",60}};
    vector<pair<Operation, pair<string, int>>> operations = {
        {Operation::REMOVE_FRONT, {"", 0}}, 
        {Operation::ADD_FRONT, {"Eat", 15}}, 
        {Operation::ADD_BACK, {"Groom", 45}} 
    };

    deque<pair<string, int>> learnerResult = ManagePetSchedule(initialActivities, operations);

    std::cout << "Your code returned: { ";

    for (const auto& activity : learnerResult)
        std::cout << "{" << activity.first << ", " << activity.second << "} ";
    
    std::cout << "}" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}

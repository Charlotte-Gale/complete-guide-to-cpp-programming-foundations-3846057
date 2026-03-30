// Complete Guide to C++ Programming Foundations
// Challenge 04_11
// Vector Manipulation, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>

std::vector<int> SelectKeyPoints(std::vector<int> distances, int checkpointIndex){
    
    const int start = distances[0];
    const int checkpoint = distances[checkpointIndex];
    const int end = distances.back();

    std::vector<int> result = { start, checkpoint, end };
    
    return result;
}

int main(){
    std::vector<int> distances = {3, 5, 4, 6, 7, 8};
    int checkpointIndex = 4;

    std::vector<int> learnerResult = SelectKeyPoints(distances, checkpointIndex);
    std::cout << "Your code returned: { ";
    auto vectPtr = learnerResult.begin();
    while (vectPtr != learnerResult.end()){
        std::cout << *vectPtr << " ";
        vectPtr = next(vectPtr, 1);
    }
    std::cout << "}" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}

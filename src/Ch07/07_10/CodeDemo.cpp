// Complete Guide to C++ Programming Foundations
// Challenge 07_10
// Design a Person Class, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

class Person{
public:
    Person(const std::string& name, float energy, float happiness, float health) : name(name), energy(energy), happiness(happiness), health(health){};

    void Eat(float calories){
        if (energy < 100){
            energy += (calories * 7.0 / 200.0);
        }
    }
    
    void Play(float minutes){
        if (happiness < 100 && energy > 0){
            happiness += (minutes / 2.0);
            energy -= (minutes / 3.0);
        }
    }

    void Sleep(float hours){
        if (energy < 100) {
            energy += (hours * 3.75);
        }

        if (health < 100) {
            health += (hours * 2.5);
        }
    }

    float GetEnergy() const{
        return energy;
    }

    float GetHappiness() const{
        return happiness;
    }

    float GetHealth() const{
        return health;
    }
private:
    std::string name;
    float energy;
    float happiness;
    float health;
};


int main(){
    // Example 1
    std::string name = "Alice";
    float energy = 40;
    float happiness = 22;
    float health = 80;

    float calories = 300;
    float playMinutes = 120;
    float sleepHours = 5;

    Person sporty(name, energy, happiness, health);
    sporty.Eat(calories);
    sporty.Play(playMinutes);
    sporty.Sleep(sleepHours);

    std::cout << "Your code returned: { ";
    std::cout << "Energy: " << sporty.GetEnergy() << ", ";
    std::cout << "Happiness: " << sporty.GetHappiness() << ", ";
    std::cout << "Health: " << sporty.GetHealth() << " }" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
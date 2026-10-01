#include <iostream>
#include <string>

class Character{
private:
    std::string name;
    int hp;

public:
    Character(const std::string& newName, const int& newHp){
        name = newName;
        hp = newHp;
    }

    void takeDamage(const int& damage){
        hp -= damage;
    }

    void printInfo(){
        std::cout << name << "'s hp: " << hp << std::endl;
    }

    std::string getName(){
        return name;
    }

    virtual void speak(){
        std::cout << "Character speak" << std::endl;
    }
};

class Player : public Character{
private:
    int level;

public:
    Player(const std::string& newName, const int& newHp, const int& newLevel)
        : Character(newName, newHp){
        level = newLevel;
    }

    void levelUp(){
        level += 1;
    }

    void printPlayerInfo(){
        std::cout << getName() << "'s level: " << level << std::endl; 
    }

    void speak() override{
        std::cout << "Player speak" << std::endl;
    }
};

int main(){
    Character* character = new Player("Bob", 100, 1);
    character->speak();
    delete character;
}
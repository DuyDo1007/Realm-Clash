#ifndef PARTICIPANT
#define PARTICIPANT
#include <string>
#include <vector>
#include <unordered_map>
enum Resources
{
    Wood,
    Stone,
    Iron,
    Gold
};

struct Player
{
    int FD; 
    std::string Name;   
    int TeamID;    
};

struct Team
{
    int ID;
    std::string Name;
    std::vector<int> Members;
    std::vector<int> Inventory; /*Store Items*/
    std::unordered_map<Resources,int> ResourceQuantity;
};
std::unordered_map<Resources, int> RESOURCE_MINE_AMOUNT = {
    { Resources::Wood,  30 },
    { Resources::Stone, 15 },
    { Resources::Iron,   5 }
};
std::unordered_map<int,Team> Teams;

#endif
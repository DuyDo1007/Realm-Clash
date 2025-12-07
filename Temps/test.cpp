#include <iostream>
#include "Models/Part.hpp"

using namespace std;

// Hàm khởi tạo Teams với tài nguyên cố định
void InitializeTeams() {
    // Khởi tạo Team A (ID = 1)
    // Wood: 10000, Stone: 100, Iron: 10000, Gold: 10000
    Team teamA;
    teamA.ID = 1;
    teamA.Name = "A";
    teamA.ResourceQuantity = {
        {Resources::Wood, 10000},
        {Resources::Stone, 100},
        {Resources::Iron, 10000},
        {Resources::Gold, 10000}
    };
    Teams[1] = teamA;
    
    // Khởi tạo Team B (ID = 2)
    // Wood: 2000, Stone: 2000, Iron: 2000, Gold: 2000
    Team teamB;
    teamB.ID = 2;
    teamB.Name = "B";
    teamB.ResourceQuantity = {
        {Resources::Wood, 2000},
        {Resources::Stone, 2000},
        {Resources::Iron, 2000},
        {Resources::Gold, 2000}
    };
    Teams[2] = teamB;
    
    // Khởi tạo Team C (ID = 3)
    // Wood: 1500, Stone: 2000, Iron: 0, Gold: 10000
    Team teamC;
    teamC.ID = 3;
    teamC.Name = "C";
    teamC.ResourceQuantity = {
        {Resources::Wood, 7000},
        {Resources::Stone, 2000},
        {Resources::Iron, 5000},
        {Resources::Gold, 10000}
    };
    Teams[3] = teamC;
    
    // // In ra thông tin các team đã khởi tạo
    // cout << "=== Teams Initialized ===" << endl;
    // for (const auto& pair : Teams) {
    //     const Team& t = pair.second;
    //     cout << "\nTeam " << t.Name << " (ID: " << t.ID << "):" << endl;
    //     cout << "  Wood: " << t.ResourceQuantity.at(Resources::Wood) << endl;
    //     cout << "  Stone: " << t.ResourceQuantity.at(Resources::Stone) << endl;
    //     cout << "  Iron: " << t.ResourceQuantity.at(Resources::Iron) << endl;
    //     cout << "  Gold: " << t.ResourceQuantity.at(Resources::Gold) << endl;
    // }
}

// Hàm khởi tạo Castles
void InitializeCastles(Building& building) {
    // Castle 1 - bị Team A chiếm đóng
    Castle castle1;
    castle1.castleID = 1;
    castle1.ownerTeamID = 1; // Team A
    castle1.defensePoints = 0;
    building.Castles[1] = castle1;
    
    // Castle 2 - chưa bị chiếm đóng
    Castle castle2;
    castle2.castleID = 2;
    castle2.ownerTeamID = -1; // Chưa có chủ
    castle2.defensePoints = 0;
    building.Castles[2] = castle2;
    
    // Castle 3 - bị Team B chiếm đóng
    Castle castle3;
    castle3.castleID = 3;
    castle3.ownerTeamID = 2; // Team B
    castle3.defensePoints = 0;
    building.Castles[3] = castle3;
    
    // // In ra thông tin các castle đã khởi tạo
    // cout << "\n=== Castles Initialized ===" << endl;
    // for (const auto& pair : building.Castles) {
    //     const Castle& c = pair.second;
    //     cout << "\nCastle " << c.castleID << ":" << endl;
    //     if (c.ownerTeamID != -1) {
    //         cout << "  Owner: Team " << Teams[c.ownerTeamID].Name << endl;
    //     } else {
    //         cout << "  Owner: None (Not occupied)" << endl;
    //     }
    //     cout << "  Defense Points: " << c.defensePoints << endl;
    // }
}

int main() {
    InitializeTeams();
    
    Building building;
    InitializeCastles(building);

    int ret = BuyDefense(&building.Castles[1], &Teams[1], FENCE);
    cout << ret << endl;
    GetTeamResourceInfo(1);

    GetCastleInfo(building,1);

    ret = BuyWeapon(&Teams[3], CATAPULT);
    ret = BuyWeapon(&Teams[3], BALLISTA);
    cout << ret << endl;
    GetTeamResourceInfo(3);
    cout << Teams[3].Inventory.size() << endl;
    ret = AttackCastle(&building.Castles[1],&Teams[3],CATAPULT);
    cout << ret << endl;
    GetCastleInfo(building,1);
}

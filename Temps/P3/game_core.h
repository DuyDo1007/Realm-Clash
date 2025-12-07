#ifndef GAME_CORE_H
#define GAME_CORE_H

#include <stdio.h>
#include <string.h>

// --- CẤU HÌNH ---
#define MAX_TEAMS 5
#define MAX_SPOTS 6
#define MAX_CASTLES 3

#define MAX_WOOD_SLOTS 2
#define MAX_STONE_SLOTS 2
#define MAX_IRON_SLOTS 2

#define WOOD_YIELD 30
#define STONE_YIELD 15
#define IRON_YIELD 5
#define GOLD_YIELD 5

// --- STRUCTS ---
typedef struct {
    int wood;
    int stone;
    int iron;
    int gold;
} Resource;

typedef struct {
    int id;
    char name[20];
    Resource currentRes;
    int countWoodSlots;
    int countStoneSlots;
    int countIronSlots;
} Team;

typedef struct {
    int id;
    int ownerWoodSlot; 
    int ownerStoneSlot;
    int ownerIronSlot;
} Spot;

typedef struct {
    int id;
    int ownerId;
    int currentDef;
} Castle;

typedef struct {
    Team teams[MAX_TEAMS];
    Spot spots[MAX_SPOTS];
    Castle castles[MAX_CASTLES];
} Map;

// --- KHAI BÁO HÀM (Prototypes) ---
void initMap(Map *map);
void answerSpotQuestion(Map *map, int teamId, int spotId, int type);
void answerCastleQuestion(Map *map, int teamId, int castleId);
void accumulateResources(Map *map);
void printTeamStatus(Map *map);

#endif
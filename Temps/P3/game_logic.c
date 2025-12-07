#include "game_core.h"

void initMap(Map *map) {
    for (int i = 0; i < MAX_TEAMS; i++) {
        map->teams[i].id = i;
        sprintf(map->teams[i].name, "Team %d", i + 1);
        map->teams[i].currentRes = (Resource){0, 0, 0, 0};
        map->teams[i].countWoodSlots = 0;
        map->teams[i].countStoneSlots = 0;
        map->teams[i].countIronSlots = 0;
    }

    for (int i = 0; i < MAX_SPOTS; i++) {
        map->spots[i].id = i;
        map->spots[i].ownerWoodSlot = -1;
        map->spots[i].ownerStoneSlot = -1;
        map->spots[i].ownerIronSlot = -1;
    }

    for (int i = 0; i < MAX_CASTLES; i++) {
        map->castles[i].id = i;
        map->castles[i].ownerId = -1;
        map->castles[i].currentDef = 0;
    }
}

void answerSpotQuestion(Map *map, int teamId, int spotId, int type) {
    Team *team = &map->teams[teamId];
    Spot *spot = &map->spots[spotId];

    // Kiểm tra giới hạn slot
    if ((type == 0 && team->countWoodSlots >= MAX_WOOD_SLOTS) ||
        (type == 1 && team->countStoneSlots >= MAX_STONE_SLOTS) ||
        (type == 2 && team->countIronSlots >= MAX_IRON_SLOTS)) {
        printf("[!] Team %d da dat gioi han slot loai nay!\n", teamId + 1);
        return;
    }

    int *currentOwner = (type == 0) ? &spot->ownerWoodSlot : 
                        (type == 1) ? &spot->ownerStoneSlot : &spot->ownerIronSlot;
    
    int *counter = (type == 0) ? &team->countWoodSlots :
                   (type == 1) ? &team->countStoneSlots : &team->countIronSlots;

    if (*currentOwner != -1) {
        printf("[!] Slot nay da co chu, khong the chiem de!\n");
        return;
    }

    *currentOwner = teamId;
    (*counter)++;
    printf("[+] Team %d chiem thanh cong Slot tai Bai %d!\n", teamId + 1, spotId);
}

void answerCastleQuestion(Map *map, int teamId, int castleId) {
    Castle *castle = &map->castles[castleId];
    if (castle->ownerId == -1) {
        castle->ownerId = teamId;
        printf("[+] Team %d da chiem Lau dai %d!\n", teamId + 1, castleId);
    } else {
        printf("[!] Lau dai %d da co chu (Team %d). Can tan cong!\n", castleId, castle->ownerId + 1);
    }
}

void accumulateResources(Map *map) {
    printf("\n>>> HE THONG DANG CONG TAI NGUYEN (TICK) <<<\n");
    for (int i = 0; i < MAX_SPOTS; i++) {
        Spot *s = &map->spots[i];
        if (s->ownerWoodSlot != -1) map->teams[s->ownerWoodSlot].currentRes.wood += WOOD_YIELD;
        if (s->ownerStoneSlot != -1) map->teams[s->ownerStoneSlot].currentRes.stone += STONE_YIELD;
        if (s->ownerIronSlot != -1) map->teams[s->ownerIronSlot].currentRes.iron += IRON_YIELD;
    }
    for (int i = 0; i < MAX_CASTLES; i++) {
        if (map->castles[i].ownerId != -1) {
            map->teams[map->castles[i].ownerId].currentRes.gold += GOLD_YIELD;
        }
    }
}

void printTeamStatus(Map *map) {
    printf("\n%-10s | %-6s | %-6s | %-6s | %-6s\n", "TEAM", "GOLD", "IRON", "STONE", "WOOD");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < MAX_TEAMS; i++) {
        Resource r = map->teams[i].currentRes;
        printf("%-10s | %-6d | %-6d | %-6d | %-6d\n", 
               map->teams[i].name, r.gold, r.iron, r.stone, r.wood);
    }
    printf("----------------------------------------------------\n");
}
#include "game_core.h"

int main() {
    Map gameMap;
    initMap(&gameMap);
    
    printf("--- BAT DAU GAME ---\n");
    
    // Test logic
    answerSpotQuestion(&gameMap, 0, 0, 0); // Team 1 chiếm Gỗ bãi 0
    answerSpotQuestion(&gameMap, 1, 0, 1); // Team 2 chiếm Đá bãi 0
    answerCastleQuestion(&gameMap, 0, 0);  // Team 1 chiếm Lâu đài 0

    accumulateResources(&gameMap); // Cộng tiền lần 1
    printTeamStatus(&gameMap);

    accumulateResources(&gameMap); // Cộng tiền lần 2
    printTeamStatus(&gameMap);

    return 0;
}
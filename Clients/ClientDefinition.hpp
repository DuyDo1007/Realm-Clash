#ifndef CLIENT_DEFINITION
#define CLIENT_DECLARATION

#define LOG_NONE							FG_GREEN ""
#define LOG_UNKNOWN_COMMAND					FG_RED "Unknown command!"

#define LOG_LOBBY_WRONG_TEAM				FG_RED "Joined in wrong team!"
#define LOG_LOBBY_REQUEST_FULL				FG_RED "Joining request failed: Request list is full!"

//
#define CODE_NULL							"NULL"

// Client phases
#define PHASE_WELCOME                       000

#define PHASE_LOBBY_JOINING_READY           100
#define PHASE_LOBBY_JOINING_PENDING			101		

#define PHASE_LOBBY_JOINED_MEMBER           110
#define PHASE_LOBBY_JOINED_RLEADER          111                
#define PHASE_LOBBY_JOINED_TLEADER          112                
#define PHASE_LOBBY_JOINED_RTLEADER         113     

#endif
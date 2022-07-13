#include "defs.h"

// Bitboards

// [side to move][square index ]
U64 pawn_attack_table[2][64]; 
U64 knight_attack_table[64];
U64 king_attack_table[64];
U64 queen_attack_table[64];

// [attacker square][magic hash]
U64 bishopAttackTable[64][512]; 
U64 rookAttackTable[64][4096];

// Magic bitboards for pins
/* We use magic bitboards to generate pinmasks for legal move generation */
U64 bishopPinTable[64][512]; 
U64 rookPinTable[64][4096]; 


// Board representation

U64 bitboards[12];
U64 occupancies[3];
char piece_on_square[64];

int side_to_move;
int castling_rights;
int en_passent_legal;
int en_passent_square;
int ply;
int game_depth;
int fifty_move;
U64 hash;

char *piece_characters = "KPNBRQkpnbrq.";
char char_to_piece_code[] = {
    ['K'] = K,
    ['P'] = P,
    ['N'] = N,
    ['B'] = B,
    ['R'] = R,
    ['Q'] = Q,
    ['k'] = k,
    ['p'] = p,
    ['n'] = n,
    ['b'] = b,
    ['q'] = q,
    ['r'] = r,
    ['.'] = EMPTY
};

char *square_strings[64] = {
    "a1","b1","c1","d1","e1","f1","g1","h1",
    "a2","b2","c2","d2","e2","f2","g2","h2",
    "a3","b3","c3","d3","e3","f3","g3","h3",
    "a4","b4","c4","d4","e4","f4","g4","h4",
    "a5","b5","c5","d5","e5","f5","g5","h5",
    "a6","b6","c6","d6","e6","f6","g6","h6",
    "a7","b7","c7","d7","e7","f7","g7","h7",
    "a8","b8","c8","d8","e8","f8","g8","h8"
};

char *promoted_pieces= "nbrq";

// Move and history stack
_move_list move_stack;
int moves_start_idx[MAX_PLY];
hist_t game_history[MAX_HIST];


// Search

// Search nodes
U64 nodes;

// UCI
char *starting_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char *kiwipete = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ";
char *cmk_position = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";
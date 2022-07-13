#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Bitboards
void print_bitboard(U64 bb);
int bitscanForward(U64 bb);
int popcount32(U32 bb);
int popcount(U64 bb);
int popcount_sparse(U64 bb);

void generate_magic_numbers();

void init_jumper_attack_masks();
void init_slider_attack_masks();

U64 bishop_attack_mask(int, U64);
U64 rook_attack_mask(int, U64);
U64 kingAttacks(int sq);
U64 knightAttacks(int sq);
U64 pawnAttacks(int side, int sq);
U64 bishopAttacks(int sq, U64 occ);
U64 rookAttacks(int sq, U64 occ);
U64 queenAttacks(int sq, U64 occ);

U64 bishopPinAttacks(int sq, U64 occ);
U64 rookPinAttacks(int sq, U64 occ);

U64 rankfile_pinmask();
U64 diagonal_pinmask();

// Board Representation
void print_board();
void parse_fen(char *fen);

void print_move(U16);
void print_move_stack(int);

int is_square_attacked(int, int);
int in_check(int);
void generate_moves();
void generate_captures();
 
int make_move(U16);
int make_capture(U16);
void unmake_move();

void perft_test(int);
void divide(int);

// Search and evaluation
void clear_tables();

int score_move(U16);
void score_moves();
void sort_moves();

int eval();
void search(int);
void print_move_scores();

// UCI
int get_time_ms();
void reinit_timing();
void communicate();

U16 parse_move(char *);
void parse_position(char *);
void parse_go(char *);
void uci();

// main
void prepare_search();
void init_all();
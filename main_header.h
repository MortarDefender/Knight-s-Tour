#pragma once
#define M 8  // COLS
#define N 8  // ROWS
#define BORDER '|'
#define OPEN   ' '
#define CLOSE  '*'

#define isdigit(x) (x < '0' || x > '9') ? 0 : 1
#define position(x) ((x - 'A' >= 0) ? (x - 'A' + 1) : (x - '0' + 1))
#define gotopos(start) (start[0] - 'A' >= 0) ? (gotoxy(position(start[0]), position(start[1]))) : (gotoxy(position(start[1]), position(start[0])))
#define isbetween(start, end, x) ((start < x) && (x < end)) ? 1 : 0

#define calcPos(x) ((x - 'A' >= 0) ? (x - 'A') : (x - '0' - 1))
#define convletter(x) (x + 'A')
#define convnumber(x) (x + '0' + 1)

typedef char boardPos[2];
typedef struct _treeNodeListCell treeNodeListCell;  // forward declarations
typedef struct _treeNode treeNode;                  // forward declarations

// define struct
typedef struct _move {
	char rows, cols;   // is it a number -1 / 1 or a char like boardPos but divided
} Move;

typedef struct _moveArray {
	unsigned int size;
	Move* moves;             // array of moves?
} movesArray;

typedef struct _boardPosArray {
	unsigned int size;
	boardPos* positions;
} boardPosArray;

typedef struct _moveCell {
	Move move;
	struct _moveCell* next;
	struct _moveCell* prev;
} moveCell;

typedef struct _movesList {
	moveCell* head;
	moveCell* tail;
} movesList;

typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _treeNode {
	boardPos position;
	treeNodeListCell* next_possible_position;
} treeNode;

typedef struct _pathTree {
	treeNode* head;
} pathTree;

typedef struct _boardPosList {
	boardPos position;
	struct _boardPosList* next;
} boardPosList;

typedef struct _linkedList {
	int row, col;
	struct _linkedList* next;
} LinkList;

typedef struct _list {
	LinkList* head;
	LinkList* tail;
} PointList;

// function declaration
boardPosArray** validMoves(movesArray** moves, char** board);
void remove_move(movesArray* moves, int index);
int check_move(boardPos start, char** board, char row, char col);

int display(movesList* moves_list, boardPos start, char** board);
int display2(movesList* moves_list, boardPos start, char** board);
int remove_duplicate(movesList* move_list);

void gotoxy(int x, int y);
void craft_border();
char** craft_border2();

pathTree findAllPossiblePaths(boardPos* startingPosition);
treeNodeListCell* createBranch(boardPos start, char** board, int level);
treeNodeListCell* createBranch2(boardPos start, char** board, int level);
void change_board(char** board, PointList lst, bool flag);

char** create_board(char** board);

boardPosList* findKnightPathConveringAllBoard(boardPos* startingPosition);
int calc_route(treeNode* head, boardPosList* route_list);
// Test
boardPosList* treeHuristic(boardPos* start);
boardPosList* createTree(boardPos start, char** board);

void saveListToBinFile(char* file_name, boardPosList* pos_list);
void writeBin(char* file_name, boardPos pos);

int checkAndDisplayPathFromFile(char* file_name);

void get_file_name(char** file_namep);
void menu();

//DLC
void menu_screen();
void replace(char* file_name, char* old, char* new);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "main_header.h"

#define DEBUG  1
#define DEBUG2 0
#define DLC 1

//******************MAIN*********************//
int main(int argc, char* argv[]) {
	//                 row, col
	/*boardPos start  = { 'A', '2' };
	boardPos start2 = { 'B', '3' };
	boardPos start3 = { 'C', '4' };
	craft_border();
	gotopos(start);
	printf("#");
	gotopos(start2);
	printf("#");
	gotopos(start3);
	printf("#");
	gotoxy((M*2)+5, 0);*/

	menu();

	/*char index = '1';
	char a = 'A';
	while ((index - '0') < 9) {
		printf("(%c, %c) = (%d, %d) = (%c, %c) || ", a, index, calcPos(a), calcPos(index), convletter(calcPos(a)), convnumber(calcPos(index)));
		printf(" between = %d\n", (isbetween(-1, N, calcPos(a)) == 1 && isbetween(-1, M, calcPos(index)) == 1));
		index++;
		a++;
	}*/

	/*boardPos start = { 'D', '4' };
	pathTree tree;
	tree = findAllPossiblePaths(&start);
	printf("done\n");*/

	// start huristic
	//boardPosList* t = treeHuristic(&start);
	
	/*char** board = (char**)malloc((N+1) * sizeof(char*));
	char* line;
	for (int i = 0; i < N; i++) {
		line = (char*)malloc(((M * 3) + 1) * sizeof(char));
		for (int j = 0; j < M; j++) {
			line[j] = OPEN;
		}
		board[i] = line;
	}
	
	// DISPLAY route
	int k, j, index, spot = 2;                   // init for loop variable
	char col = 'A';
	for (k = 0; k < N + 1; k++) {                // start a first for loop
		line = (char*)malloc(((M * 3) + 1) * sizeof(char));
		for (j = 0, index = 1; j < (M * 3) + 1; j++) { // start a second for loop
			if (k == 0) {                      // check if it is the first of last row
				if (j == spot) { 
					line[j] = index + '0';
					spot += 3;
					index++;
				}
				else { 
					line[j] = OPEN;
				}
			}
			else {                           // else
				if (j == 0) {                // check if it is the first of last columm
					line[j] = col;         // if it is print the BORDER
					col++;
				}
				else {                         // else
					line[j] = OPEN;      // print SPACE
				}
			}
		}                                    // end second for loop
		board[k] = line;
	}                                        // end first for loop

	boardPosList* head = t;
	int count = 0; // , digit;
	index = 1, spot = 1;
	while (head != NULL) {
		if (DEBUG2)
			printf("%d,%d ", calcPos(head->position[0]), calcPos(head->position[1]));
		//printf("position: (%c,%c)\n", head->position[0], head->position[1]);
		count++;
		if (index < 10) {
			board[position(head->position[0])][(position(head->position[1]) * 3) - 4] = index + '0';
		}
		else {
			board[position(head->position[0])][(position(head->position[1]) * 3) - 4] = (index / 10) + '0';
			board[position(head->position[0])][(position(head->position[1]) * 3) - 4 + 1] = (index % 10) + '0';
		}
		index++;
		head = head->next; 
	}
	printf("\n");
	for (int i = 0; i < (N+1); i++) { for (int l = 0; l < ((M * 3) + 1); l++) { printf("%c", board[i][l]); } printf("\n"); }

	//printf("amount - %d\n", count);

	printf("done\n");*/
	
	//saveListToBinFile("knight's tour.txt", t);
	//system("python knight.py");

	//printf("\nres - %d\nDONE", checkAndDisplayPathFromFile("knight's tour.txt"));

	// EX. E
	/*
	boardPos start = { 'C', '5' };
	boardPos start2 = { 'A', '4' };
	boardPos start3 = { 'B', '3' };
	boardPos start4 = { 'D', '1' };
	boardPos start5 = { 'E', '3' };
	boardPosList* arr =  (boardPosList*)malloc(sizeof(boardPosList));
	boardPosList* arr2 = (boardPosList*)malloc(sizeof(boardPosList));
	boardPosList* arr3 = (boardPosList*)malloc(sizeof(boardPosList));
	boardPosList* arr4 = (boardPosList*)malloc(sizeof(boardPosList));
	boardPosList* arr5 = (boardPosList*)malloc(sizeof(boardPosList));

	arr->position[0] = start[0];
	arr->position[1] = start[1];
	arr2->position[0] = start2[0];
	arr2->position[1] = start2[1];
	arr3->position[0] = start3[0];
	arr3->position[1] = start3[1];
	arr4->position[0] = start4[0];
	arr4->position[1]= start4[1];
	arr5->position[0] = start5[0];
	arr5->position[1] = start5[1];

	arr->next = arr2;
	arr2->next = arr3;
	arr3->next = arr4;
	arr4->next = arr5;
	arr5->next = NULL;

	writeBin("score.txt", start4);
	saveListToBinFile("score2.txt", arr);
	*/
}

// A
boardPosArray** validMoves(movesArray** moves, char** board) {
	// moves is a two dim array of the board -> in evey cell there is the posiible moves from this point
	// ths size is the same as in moves as board
	// every cell in board can have: <space> -> can move / * -> can not move
	/* remove illegal moves from moves array
	   an illegal move is:
	   1. move into a cell with *.
	   2. out of bound move */
	int row_index = 0, col_index = 0;
	movesArray* move_row;
	while (col_index < N) {
		col_index = 0;
		move_row = moves[row_index];
		while (col_index < move_row->size) {
			// check if the move is out of bound
			// check if the next cell is *
			// move_row[col_index].rows: positive = down, neg = up
			// move_row[col_index].cols: positive = right, neg = left
			if (move_row->moves[col_index].rows > 0) {
				if (row_index + move_row->moves[col_index].rows > N) { char s[] = "not valid"; }
			}
			else {
				if (row_index + move_row->moves[col_index].rows < 0) { char s[] = "not valid"; }
			}

			if (move_row->moves[col_index].cols > 0) {
				if (col_index + move_row->moves[col_index].cols > M) { char s[] = "not valid"; }
			}
			else {
				if (col_index + move_row->moves[col_index].cols > 0) { char s[] = "not valid"; }
			}

			if (board[row_index + move_row->moves[col_index].rows][col_index + move_row->moves[col_index].cols] == '*') { char s[] = "not valid"; }
		}
		row_index++;
	}
}

boardPosArray** validMoves2(movesArray** moves, char** board) {  // movesAeeay is the size of the board ?
	boardPosArray** pos = (boardPosArray**)malloc(N * sizeof(boardPosArray*));
	boardPosArray* posssible_row;
	movesArray* move_arr = *(moves);
	int read = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			// check if the move is out of bound
			// check if the next cell is *
			// move_arr[col].moves->rows: positive = down, neg = up
			// move_arr[col].moves->cols: positive = right, neg = left
			posssible_row = (boardPosArray*)malloc(sizeof(boardPosArray));
			for (int index = 0; index < move_arr[col].size; index++) {
				// check first and last rows and cols -> remove the 1 or not
				if ((isbetween(1, N, (row + 1) + move_arr[col].moves[index].rows)) || (isbetween(1, M, (col + 1) + move_arr[col].moves[index].cols)) || (board[row + move_arr[col].moves[index].rows][col + move_arr[col].moves[index].cols] == '*')) {
					remove_move(&(move_arr[col].moves), col);
				}
				// boardPos start; start[0] = row; start[1] = col;
				// if (check_move(start, board, move_arr[col].moves[index].rows, move_arr[col].moves[index].cols)) {remove_move(&(move_arr[col].moves), col);}
				//  1 2 3 4
				// A_ _ _ _
				// B_ X _ _
				// C_ _ _ _
				// D_ _ _ _
				//  1 < X < N
				//  1 < X < M
			}
			posssible_row->positions = move_arr->moves;
			posssible_row->size = move_arr->size;
			pos[read]->positions = posssible_row;
		}
	}
}

int check_move(boardPos start, char** board, char row, char col) {
	if ((isbetween(1, N, (start[0] + 1) + row)) ||
		(isbetween(1, M, (start[1] + 1) + col)) ||
		((board != NULL) && (board[start[0] + row][start[1] + col] == '*'))) {
		return 0;
	}
	return 1;
}


void remove_move(movesArray* moves, int index) {
	// while ((i < move->size) && ()) { i++; }
	int i = index + 1;
	Move move = moves->moves[index];
	Move temp;

	while (i + 1 < moves->size) {
		moves->moves[i] = moves->moves[i + 1];
		i++;
	}
	moves->moves[i] = move;
	moves->size -= 1;
	//free(moves->moves[i]);
}

// B
int display(movesList* moves_list, boardPos start, char** board) {
	// draw the moves in moves list to the user by starting with # and move to 1...n
	// if there is a move that has been in the move will be deleted

	// version 1
	//int del_rows = remove_duplicate(moves_list);

	// draw the board and the moves
	// version 2
	moveCell* head = moves_list->head;
	moveCell* temp;
	char** dummy_board = board;
	dummy_board[start[0]][start[1]] = "#";
	int index = 1;
	int del_rows = 0;

	while (head != NULL) {
		if (isdigit(dummy_board[head->move.rows][head->move.cols]) == 1) {
			// there will be always prev
			head->prev->next = head->next;
			if (head->next != NULL) { head->next->prev = head->prev; }
			else { moves_list->tail = head->prev; }

			temp = head->next;
			free(head);
			head = temp;

			del_rows += 1;
		}
		else {
			dummy_board[head->move.rows][head->move.cols] = '0' + index;
			head = head->next;
			index++;
		}
	}

	// draw the screen
	craft_border();
	gotoxy(start[0] - 'A' + 2, start[1] - '0' + 1);
	printf("#");
	gotoxy(10, 10);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			gotoxy(j, i);
			if (isdigit(dummy_board[i][j])) { printf("%c", dummy_board[i][j]); }
			else {
				printf("%c", OPEN);
				// printf("%c", dummy_board[i][j]);
			}
		}
	}

	return del_rows;
}

int display2(movesList* moves_list, boardPos start, char** board) {
	movesList lst = *(moves_list);
	moveCell* head = lst.head;
	moveCell* temp;

	int del_rows = 0, index = 1;
	
	char** dummy_board = craft_border2();
	// dummy_board[calcPos(position[0])][position(start[1] * 3) - 4] = '#';

	while (head != NULL) {
		if (isdigit(dummy_board[position(head->move.rows)][position(head->move.cols)*3 - 4]) == 1) {
			// there will be always prev
			head->prev->next = head->next;
			if (head->next != NULL) { head->next->prev = head->prev; }
			else { moves_list->tail = head->prev; }

			temp = head->next;
			free(head);
			head = temp;

			del_rows += 1;
		}
		else {
			if (index < 10) {
				dummy_board[position(head->move.rows)][(position(head->move.cols) * 3) - 4] = index + '0';
			}
			else {
				dummy_board[position(head->move.rows)][(position(head->move.cols) * 3) - 4] = (index / 10) + '0';
				dummy_board[position(head->move.rows)][(position(head->move.cols) * 3) - 4 + 1] = (index % 10) + '0';
			}
			head = head->next;
			index++;
		}
	}

	// draw the screen
	for (int i = 0; i < (N + 1); i++) { for (int l = 0; l < ((M * 3) + 1); l++) { printf("%c", dummy_board[i][l]); } printf("\n"); }
	return del_rows;
}

int remove_duplicate(movesList* move_list) {
	int del_rows = 0;
	moveCell* start_head = move_list->head;

	if (start_head->next == NULL)
		return del_rows;

	moveCell* curr_head = move_list->head->next;
	moveCell* temp;

	while (start_head != NULL) {
		while (curr_head != NULL) {
			if (start_head->move.cols == curr_head->move.cols && start_head->move.rows == curr_head->move.rows) {
				curr_head->prev->next = curr_head->next;
				if (curr_head->next != NULL) { curr_head->next->prev = curr_head->prev; }
				else { move_list->tail = curr_head->prev; }

				temp = curr_head->next;
				free(curr_head);
				curr_head = temp;

				del_rows += 1;
			}
			else { curr_head = curr_head->next; }
		}
		start_head = start_head->next;
	}

	return del_rows;
}

void craft_border() {
	/* create a border in the game */
	int k, j, index, spot = 2;                                // init for loop variable
	char col = 'A';

	for (k = 0; k < N + 1; k++) {                // start a first for loop
		for (j = 0, index = 1; j < (M * 3) + 1; j++) { // start a second for loop
			if (k == 0) {                      // check if it is the first of last row
				if (j == spot) {
					printf("%d", index);
					spot += 3;
					index++;
				}
				else {
					printf("%c", OPEN);
				}
			}
			else {                           // else
				if (j == 0) {                // check if it is the first of last columm
					printf("%c", col);       // if it is print the BORDER
					col++;
				}
				else {                         // else
					printf("%c", OPEN);    // print SPACE
				}
			}
		}                                    // end second for loop
		printf("\n");
	}                                        // end first for loop
}

char** craft_border2() {
	/* create a border in the game */
	int k, j, index, spot = 2;                               // init for loop variable
	char col = 'A';                                          // init the side of the border
	char** board = (char**)malloc((N + 1) * sizeof(char*));  // init the board
	char* line;                                              // init line for later use
	for (k = 0; k < N + 1; k++) {                            // start a first for loop
		line = (char*)malloc(((M * 3) + 1) * sizeof(char));  // init and save memory for line
		for (j = 0, index = 1; j < (M * 3) + 1; j++) {       // start a second for loop
			if (k == 0) {                                    // check if it is the first row
				if (j == spot) {                             // check if j is spot -> to insert the number in the right location
					line[j] = index + '0';                   // insert index as a char into line in place j
					spot += 3;                               // add 3 to spot
					index++;                                 // increase index by one
				}
				else                                         // else: j is not equall to spot
					line[j] = OPEN;                          // insert OPEN to line in place j
			}
			else {                                           // else: it is not the first row
				if (j == 0) {                                // check if it is the first columm
					line[j] = col;                           // insert col as the cherecter for the border to line in place j
					col++;                                   // increase col by one
				}
				else                                         // else: it is not the first columm
					line[j] = OPEN;                          // insert to line OPEN inside line in place j
			}
		}                                                    // end second for loop
		board[k] = line;                                     // insert the line to board in place k
	}                                                        // end first for loop
	return board;                                            // return the board
}

void gotoxy(int x, int y) { printf("\x1b[%d;%df", x, y); }

// C
pathTree findAllPossiblePaths(boardPos* startingPosition) { // fix the recursive: there is added moves from prev possible moves 
	// knight path is: -/+ 2R -/+ 1C
	// check_move
	/* path Tree is a a linked list like "tree" that store the current moves and potentialy the next moves for each move
	   the path tree type workes in this order:
	   path tree is the head (root) of treeNode prototype
	   treeNode prototype is the node of the root it is the move itself - the position of the move - and the next move from that point on -> _treeNodeListCell
	   treeNodeListCell prototype is the next move from a starting position:
	   treeNode node -> it is a move from the posiblitys
	   __treeNodeListCell next -> is the other posssible moves from the strting point */

	pathTree tree;

	char** board = (char**)malloc(N * sizeof(char*));
	char* line;
	for (int i = 0; i < N; i++) { 
		line = (char*)malloc(M * sizeof(char));
		for (int j = 0; j < M; j++) {
			line[j] = OPEN;
		} 
		board[i] = line;
	} // init board to OPEN
	board[calcPos(startingPosition[0][0])][calcPos(startingPosition[0][1])] = CLOSE;

	if (DEBUG)
		for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++) { printf("%c", board[i][j]); } printf("\n"); }
	tree.head = (treeNode*)malloc(sizeof(treeNode));
	tree.head->position[0] = *(startingPosition)[0];
	tree.head->position[1] = startingPosition[0][1];
	tree.head->next_possible_position = createBranch2(*(startingPosition), board, 0);   // remove int level
	return tree;
}

treeNodeListCell* createBranch(boardPos start, char** board, int level) { // remove int level
	if (DEBUG) {
		printf("start - (%c, %c) || rec - %d\n", start[0], start[1], level);
		printf("board\n");
		for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++) { printf("%c", board[i][j]); } printf("\n"); }
	}

	if (level == M * N) { if (DEBUG) { printf("level 2. Done\n"); } return NULL; }  // M*N

	treeNode* leaf = (treeNode*)malloc(sizeof(treeNode));
	treeNodeListCell* branch = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));

	char** prevboard = (char**)malloc(N * sizeof(char*));
	char* line, * line_board;
	for (int i = 0; i < N; i++) {
		line = (char*)malloc(M * sizeof(char));
		line_board = board[i];
		for (int j = 0; j < M; j++) {
			line[j] = line_board[j];
		}
		prevboard[i] = line;
	}

	int index = 0, counter = 0;

	/*PointList prev;
	prev.head = (LinkList*)malloc(sizeof(LinkList));
	prev.tail = prev.head;
	LinkList* head = prev.head;*/
	int xArr[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yArr[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	while (index < 8) {

		if (DEBUG)
			printf("index - %d || row - %2d || col - %2d\n", index, xArr[index], yArr[index]);
		// check_move(boardPos start, char** board, char row, char col)
		// check if the move is legal and if the position hasn't been in
		if ((((isbetween(-1, N, (calcPos(start[0]) + xArr[index])) == 1) && (isbetween(-1, M, (calcPos(start[1]) + yArr[index])) == 1))) && (board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] == OPEN)) {
			counter++;

			if (DEBUG)
				printf("pos - (%d, %d)  || index - %d || row - %d || col - %d\n", calcPos(start[0]) + xArr[index], calcPos(start[1]) + yArr[index], index, xArr[index], yArr[index]);

			board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] = CLOSE;

			/*head->row = calcPos(start[0]) + row;
			head->col = calcPos(start[1]) + col;
			head->next = NULL;*/

			if (DEBUG) {
				printf("2.board\n");
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) { printf("%c", board[i][j]); }
					printf("\n");
				}
			}

			leaf->position[0] = convletter(calcPos(start[0]) + xArr[index]);
			leaf->position[1] = convnumber(calcPos(start[1]) + yArr[index]);

			for (int i = 0; i < N; i++) {
				line = (char*)malloc(M * sizeof(char));
				line_board = board[i];
				for (int j = 0; j < M; j++) {
					line[j] = line_board[j];
				}
				prevboard[i] = line;
			}

			//change_board(board, prev, true);

			leaf->next_possible_position = createBranch(leaf->position, board, level + 1);
			branch->node = leaf;
			// board[calcPos(start[0]) + row][calcPos(start[1]) + col] = OPEN; // to remove the move for the rec for the current possible moves

			for (int i = 0; i < N; i++) {
				line = prevboard[i];
				line_board = board[i];
				for (int j = 0; j < M; j++) {
					line_board[j] = line[j];
				}
				board[i] = line;
			}
			//change_board(board, prev, false);
			branch->next = createBranch(start, board, level);

			/*head->next = (LinkList*)malloc(sizeof(LinkList));
			head = head->next;
			prev.tail = head;*/

		}
		index++;
	}
	// free the last item from the prev moves (for the recursive function)

	if (counter == 0) { if (DEBUG) { printf("return NULL\n"); } return NULL; } // no possible moves availeable
	else {
		if (DEBUG) {
			printf("return branch\n");
		}
		return branch;
	}
}

treeNodeListCell* createBranch2(boardPos start, char** board, int level) { // think broad spectrom
	int index = 0, counter = 0;                                            // make a function that does just branch/cell witout changing the board -> rec not needed
	char** prev_board  = create_board(board);                              // make a function that is rec that does the tree Nodes with help from the above function
	int xArr[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yArr[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	treeNodeListCell* cell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	treeNode* tree_node = (treeNode*)malloc(sizeof(treeNode));

	if (DEBUG) {
		printf("start: (%c%c)\n", start[0], start[1]);
		for (int i = 0; i < N; i++) { for (int l = 0; l < M; l++) { printf("%c", board[i][l]); } printf("\n"); }
	}

	if (level == 2 ) { return NULL; } // stop: end case -> can be without //  M * N

	while (index < 8) {
		// check legal
     // if ((((isbetween(-1, N, (calcPos(start[0]) + xArr[index])) == 1) && (isbetween(-1, M, (calcPos(start[1]) + yArr[index])) == 1))) && (board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] == OPEN)) {
		if ((isbetween(-1, N, calcPos(start[0]) + xArr[index]) == 1) && (isbetween(-1, M, calcPos(start[1]) + yArr[index]) == 1) && (board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] == OPEN)) {
			printf("pos: - %d, %d\n", calcPos(start[0]) + xArr[index], calcPos(start[1]) + yArr[index]);
			counter++;
			board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] = CLOSE;       // close the position

			tree_node->position[0] = convletter(calcPos(start[0]) + xArr[index]);
			tree_node->position[1] = convnumber(calcPos(start[1]) + yArr[index]);

			cell->node = tree_node;
			cell->next = createBranch2(start, board, level);

			// tree_node->next_possible_position = createBranch2(tree_node->position, board, level + 1);
		}
		index++;
	}
	if (counter == 0) {
		return NULL; // no position left
	}
	else { return cell; }
}

char** create_board(char** board) {
	char** plain = (char**)malloc(N * sizeof(char*));
	char* line, * board_line;
	for (int i = 0; i < N; i++){
		line = (char*)malloc(M * sizeof(char));
		board_line = board[i];
		for (int j = 0; j < M; j++) {
			line[j] = board_line[j];
		}
		plain[i] = line;
	}
	return plain;
}

void change_board(char** board, PointList lst, bool flag) {
	LinkList* head = lst.head;
	if (head == NULL || head->next == NULL) { return; }
	while (head->next != NULL) {
		if (flag)
			board[head->row][head->col] = OPEN;
		else
			board[head->row][head->col] = CLOSE;
		head = head->next;
	}
}


// Warnsdorff huristic
boardPosList* treeHuristic(boardPos* start) {
	boardPosList* head = (boardPosList*)malloc(sizeof(boardPosList));
	head->position[0] = start[0][0];
	head->position[1] = start[0][1];

	char** board = (char**)malloc(N * sizeof(char*));
	char* line;
	for (int i = 0; i < N; i++) {
		line = (char*)malloc(M * sizeof(char));
		for (int j = 0; j < M; j++) {
			line[j] = OPEN;
		}
		board[i] = line;
	}
	board[calcPos(start[0][0])][calcPos(start[0][1])] = CLOSE;
	
	head->next = createTree(*(start), board);
	return head;
}

boardPosList* createTree(boardPos start, char** board) {
	boardPosList* head = (boardPosList*)malloc(sizeof(boardPosList));
	if (DEBUG2)
		printf("start - (%c, %c)\n", start[0], start[1]);

	int index = 0, index2, counter = 0;
	int min_moves = 8, curr_moves = 0;
	boardPos min;

	int xArr[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yArr[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	while (index < 8) {
		if ((((isbetween(-1, N, (calcPos(start[0]) + xArr[index])) == 1) && (isbetween(-1, M, (calcPos(start[1]) + yArr[index])) == 1))) && (board[calcPos(start[0]) + xArr[index]][calcPos(start[1]) + yArr[index]] == OPEN)) {
			index2 = 0, curr_moves = 0;
			while (index2 < 8) {
				if ((((isbetween(-1, N, (calcPos(start[0]) + xArr[index]) + xArr[index2]) == 1) && (isbetween(-1, M, (calcPos(start[1]) + yArr[index]) + yArr[index2]) == 1))) && (board[calcPos(start[0]) + xArr[index] + xArr[index2]][calcPos(start[1]) + yArr[index] + yArr[index2]] == OPEN)) { curr_moves++; }
				index2++;
			}

			if (DEBUG2)
				printf("pos - (%c, %c) -> %d\n", convletter(calcPos(start[0]) + xArr[index]), convnumber(calcPos(start[1]) + yArr[index]), curr_moves);

			if (min_moves > curr_moves) {
				min_moves = curr_moves;
				min[0] = convletter(calcPos(start[0]) + xArr[index]);
				min[1] = convnumber(calcPos(start[1]) + yArr[index]);
			}
		}
		index++;
	}

	board[calcPos(min[0])][calcPos(min[1])] = CLOSE;

	if (DEBUG2)
		printf("min - (%c, %c) -> %d\n", min[0], min[1], min_moves);

	head->position[0] = min[0];
	head->position[1] = min[1];

	if (min_moves == 0) { head->next = NULL; return head; } // printf("return NULL\n"); board[calcPos(min[0])][calcPos(min[1])] = CLOSE;

	head->next = createTree(min, board);
	return head;
}


// D
boardPosList* findKnightPathConveringAllBoard(boardPos* startingPosition) {
	// knights route
	pathTree tree = findAllPossiblePaths(startingPosition);
	boardPosList* route_list = (boardPosList*)malloc(sizeof(boardPosList));  // NULL
	int route_length = calc_route(tree.head, route_list);
	return (route_length == 64) ? route_list : NULL;
}

int calc_route(treeNode* head, boardPosList* route_list) {
	if (head->next_possible_position == NULL)
		route_list->next = NULL;
		return 0;
	//route_list->position = head->position;
	route_list->position[0] = head->position[0];
	route_list->position[1] = head->position[1];
	route_list->next = (boardPosList*)malloc(sizeof(boardPosList));
	route_list = route_list->next;

	int first =  calc_route(head->next_possible_position->next, route_list) + 1;
	while (head->next_possible_position->next == NULL) {
		int sec = calc_route(head->next_possible_position->next->node, route_list) + 1;
	}
}

// E - check
void saveListToBinFile(char* file_name, boardPosList* pos_list) {
	// write to the file the pos_list in this order: 
	// convert letter and numbner into 3 digits in bin: 010100000011
	//                                                  _C__5__A__4_
	// write first the amount of pos
	boardPosList* head = pos_list;
	FILE* f = fopen(file_name, "wb");
	fprintf(f, "");
	fclose(f);
	while (head != NULL) { writeBin(file_name, head); head = head->next; }
}

void writeBin(char* file_name, boardPos pos) {
	int row = calcPos(pos[0]), col = calcPos(pos[1]);
	int digit, read = 2;
	FILE* f = fopen(file_name, "a");  // file name -> "file.txt"
	if (f == NULL) { printf("an error has accured"); }

	char number[4] = "000";
	number[read + 1] = '\0';

	while (row != 0) {
		digit = row % 2;
		row /= 2;
		number[read] = digit + '0';
		read--;
	}
	fprintf(f, "%s", number);

	for (int i = 0; i < 3; i++) { number[i] = '0'; }
	read = 2;
	while (col != 0) {
		digit = col % 2;
		col = col / 2;
		number[read] = digit + '0';
		read--;
	}
	fprintf(f, "%s", number);
	fclose(f);
}

// F
int checkAndDisplayPathFromFile(char* file_name) {
	// -1 if the file doesn't exist
	//  1 if the file is not in the rigt format
	//  2 the path covers the whole board
	//  3 the path doesn't covers the whole board

	FILE* f = fopen(file_name, "rb");

	if (f == NULL) { return -1; }  // check if the file exist

	// read the file
	char* str = (char*)malloc(sizeof(char));
	int size = 1, read = 0;
	char c = fgetc(f);
	while (!feof(f)) {
		if (read + 1 > size) { size *= 2;  str = (char*)realloc(str, size * sizeof(char)); }
		str[read] = c;
		read++;
		c = fgetc(f);
	}
	str[read] = '\0';
	read++;
	if (read < size) { size = read; str = realloc(str, read * sizeof(char)); }
	fclose(f);

	// check if the file is legal
	if (strlen(str) % 3 != 0) { return 1; }
	for (int i = 0; i < size; i++) { if ((isdigit(str[i]) == 0) || str[i] > '1') { return 1; } }
	
	movesList lst;
	lst.head = lst.tail = (moveCell*)malloc(sizeof(moveCell));;
	moveCell* head = lst.head;
	moveCell* prev = NULL;


	int index = 0, sum = 0;
	bool letter = true;

	while (index < size -3) {
		sum = 0;
		sum += (str[index] - '0') * (4);
		sum += (str[index+1] - '0') * (2);
		sum += (str[index+2] - '0') * (1);

		if (letter) {
			head->move.rows = sum + 'A';
		}
		else {
			head->move.cols = sum + '1';

			if ((index + 3) < size - 3) {
				head->next = (moveCell*)malloc(sizeof(moveCell));
				head->prev = prev;
				prev = head;
				lst.tail = head;
				head = head->next;
			}
			else { head->next = NULL; }
		}
		
		letter = (letter) ? false : true;
		index += 3;
	}

	printf("Position:\n");
	moveCell* q = lst.head;
	while (q != NULL) { printf("%c%c ", q->move.rows, q->move.cols); q = q->next; }
	printf("\nCords:\n");
	q = lst.head;
	while (q != NULL) { printf("%d,%d ", calcPos(q->move.rows), calcPos(q->move.cols)); q = q->next; }
	printf("\n\n");
	boardPos start = { lst.head->move.rows ,  lst.head->move.cols };

	char** board = (char**)malloc((N + 1) * sizeof(char*));
	char* line;
	for (int i = 0; i < N; i++) {
		line = (char*)malloc(((M * 3) + 1) * sizeof(char));
		for (int j = 0; j < M; j++) {
			line[j] = OPEN;
		}
		board[i] = line;
	}

	display2(&lst, start, board);
	printf("\n\n");
	return (size / 6 == M * N) ? 2 : 3;
}

// G
void get_file_name(char** file_namep) {
	char* file_name = *(file_namep);
	int size = 1, read = 0;
	char ch;
	ch = getchar();
	ch = getchar();
	while (ch != '\n') {
		if (read + 1 > size) { size *= 2; file_name = realloc(file_name, size * sizeof(char)); }
		//printf("size - %d || read - %d || ch - %c\n", size, read, ch);
		file_name[read] = ch;
		read++;
		ch = getchar();
		//printf("arr: %s\n", file_name);
	}
	file_name[read] = '\0';
	read++;
	if (read < size) { file_name = realloc(file_name, read * sizeof(char)); }
	if ((read < 4) || (strstr(file_name, ".txt") == NULL)) { strcat(file_name, ".txt"); }
	*(file_namep) = file_name;
}

void menu() {
	// can be with args/argv
	system("cls");
	if (DLC) { menu_screen(); printf("                                                    "); }
	printf("MENU:\n");
	printf("1. Enter a knight's starting position\n");
	printf("2. Create all possible knight paths\n");
	printf("3. Find a knight path covering all board\n");
	printf("4. Save knight path covering all board to file\n");
	printf("5. Load and display path from file\n");
	printf("6. Exit\n");

	int option;
	static boardPos startingPos = { NULL, NULL };
	static pathTree possibiltys;
	static boardPosList* allPaths = NULL;

	scanf("%d", &option);

	if (isbetween(0, 7, option)) {
		if (option == 1) {
			system("cls");
			printf("Enter a knight's starting position\n");
			scanf(" %c", &(startingPos[0]));
			scanf(" %c", &(startingPos[1]));
			printf("if1 - %d || if2 - %d\n", ((isbetween(0, (N + 2), position(startingPos[0]))) == 0), ((isbetween(1, (M + 2), position(startingPos[1]))) == 0));
			while (((isbetween(0, (N + 2), position(startingPos[0]))) == 0) || ((isbetween(1, (M + 2), position(startingPos[1]))) == 0)) {
				printf("the position (%c, %c) is out of bound\n", startingPos[0], startingPos[1]);
				printf("Enter a knight's starting position\n");
				scanf(" %c", &(startingPos[0]));
				scanf(" %c", &(startingPos[1]));
				printf("if1 - %d || if2 - %d\n", ((isbetween(0, (N + 2), position(startingPos[0]))) == 0), ((isbetween(1, (M + 2), position(startingPos[1]))) == 0));
			}
			menu();
		}
		else if (option == 2) {
			if (startingPos[0] == NULL && startingPos[1] == NULL) { printf("\n\nyou havent entered the knight's starting position.\nPress 1 for back\n"); while (option != 1) { scanf("%d", &option); } menu(); }

			possibiltys = findAllPossiblePaths(&(startingPos));

			printf("\n\nknight's possible paths has been created\n");
			printf("\nPress 1 for back\n");
			while (option != 1) { scanf("%d", &option); }
			menu();
		}
		else if (option == 3) {
			//if (possibiltys.head == NULL) { possibiltys = findAllPossiblePaths(&(startingPos)); }
			if (startingPos[0] == NULL && startingPos[1] == NULL) { printf("\n\nyou havent entered the knight's starting position.\nPress 1 for back\n"); while (option != 1) { scanf("%d", &option); } menu(); }

			allPaths = findKnightPathConveringAllBoard(&(startingPos));

			printf("\n\nall knight's paths has been created\n");
			printf("\nPress 1 for back\n");
			while (option != 1) { scanf("%d", &option); }
			menu();
		}
		else if (option == 4) {
			system("cls");
			printf("please enter a file name to save all knights paths:\n");
			char* file_name = (char*)malloc(sizeof(char));
			get_file_name(&file_name);

			//if (allPaths == NULL) { allPaths = findKnightPathConveringAllBoard(&(startingPos)); }
			boardPosList* allPaths = treeHuristic(&startingPos);
			saveListToBinFile(file_name, allPaths);

			printf("\n\nAll knight's paths has been saved into: %s", file_name);
			printf("\nPress 1 for back\n");
			while (option != 1) { scanf("%d", &option); }
			menu();
		}
		else if (option == 5) {
			system("cls");
			printf("please ennter a file name to load all knights paths\n");
			char* file_name = (char*)malloc(sizeof(char));
			get_file_name(&file_name);

			int res = checkAndDisplayPathFromFile(file_name);
			char sys[30];
			sprintf(sys, "python knight.py %d %d", N, M);
			printf("system: %s", sys);
			system(sys);
			if (res == 1) {
				printf("\nthe path found in '%s' is not a legal knight's path\n", file_name);
				printf("please enter a diffrent file name to load or run option 4 to get a new path entered\n");
			}
			else if (res == 2) { printf("\nthe path has successfully been load and it is covering the whole board\n"); }
			else if (res == 3) { printf("\nthe path has successfully been load but doesn't covering the whole board\n"); }
			else if (res == -1) { printf("the file specify - '%s' - doesn't exist\n please enter a diffrent file name or create a new one with that file name\n", file_name); }
			else { printf("\nError in check function output: %d\n", res); }

			printf("\n\nknight's possible paths has been created\n");
			printf("\nPress 1 for back\n");
			while (option != 1) { scanf("%d", &option); }
			menu();
		}
		else if (option == 6) {
			printf("\n\nGood Bye.\n");
			exit;
		}
		else {
			printf("\nError\n");
		}
	}
}

// DLC
void menu_screen() {
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
		   "|@@|||||@@||||@@@@|||||@@||@@@@@@@@||@@@@@@@@@||@@||||@@||@@@@@@@@@|||@@@@@@@@@||@@@@@@@@@||@@||||@@||@@@@@@@|||\n"
		   "|@@|||@@||||||@@|@|||||@@|||||@@|||||@@|||||||||@@||||@@|||||@@||||||||||@@||||||@@|||||@@||@@||||@@||@@|||||@@|\n"
		   "|@@|@@||||||||@@||@||||@@|||||@@|||||@@|||||||||@@||||@@|||||@@||||||||||@@||||||@@|||||@@||@@||||@@||@@|||||@@|\n"
		   "|@@@||@@||||||@@|||@|||@@|||||@@|||||@@|@@@@@@||@@@@@@@@|||||@@||||||||||@@||||||@@|||||@@||@@||||@@||@@@@@@@|||\n"
		   "|@@||||@@|||||@@||||@||@@|||||@@|||||@@|||||@@||@@||||@@|||||@@||||||||||@@||||||@@|||||@@||@@||||@@||@@|||||@@|\n"
		   "|@@|||||@@||||@@|||||@|@@|||||@@|||||@@|||||@@||@@||||@@|||||@@||||||||||@@||||||@@|||||@@||@@||||@@||@@|||||@@|\n"
		   "|@@||||||@@|||@@|||||@@@@||@@@@@@@@||@@@@@@@@@||@@||||@@|||||@@||||||||||@@||||||@@@@@@@@@||@@@@@@@@||@@|||||@@|\n"
		   "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

// not et tested
void replace(char* file_name, char* old, char* new) {
	FILE* f = fopen(file_name, "rb");

	if (f == NULL) { return -1; }  // check if the file exist

	// read the file
	char* str = (char*)malloc(sizeof(char));
	int size = 1, read = 0;
	char c = fgetc(f);
	while (!feof(f)) {
		if (read + 1 > size) { size *= 2;  str = (char*)realloc(str, size * sizeof(char)); }
		str[read] = c;
		read++;
		c = fgetc(f);
	}
	str[read] = '\0';
	read++;
	if (read < size) { size = read; str = realloc(str, read * sizeof(char)); }
	fclose(f);

	// two posible ways: 1. in read change and add the new string when old is found
	//                   2. after read, save before and after the old and add the new to start and end to start

	// V.2.
	int index = 0, index2 = 0, readS = 0, sizeS = 1, sizeE = 1, readE = 0, found = 0;
	char* start = (char*)malloc(sizeof(char));
	char* end = (char*)malloc(sizeof(char));
	while (str[index] != '\0') {
		if (str[index] == old[index2]) {
			int temp = index;
			while ((str[index] != '\0' && old[index2] != '\0') && (str[index] == old[index2])) { index++; index2++; }
			if (old[index2] != '\0') { temp = index; index2 = 0; }
			else { found = 1; }
		}
		if (found == 0) {
			if (readS + 1 > sizeS) { sizeS *= 2;  start = realloc(start, sizeS * sizeof(char)); }
			start[readS] = str[index];
			readS++;
		}
		else if (found == 1) {
			if (readE + 1 > sizeE) { sizeE *= 2;  end = realloc(end, sizeE * sizeof(char)); }
			end[readE] = str[index];
			readE++;
		}
		index++;
	}
	strcat(start, new);
	strcat(start, end);
	

	// write
	FILE* g = fopen(file_name, "wb");
	fprintf(g, "%s", start);
	fclose(g);
}
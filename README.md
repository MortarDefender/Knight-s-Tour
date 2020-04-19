# Knight-s-Tour
Final Project written in c of the implementation of the known problem "Knight's Tour"

there is 4 files in this rep:
1. main.c
2. main_header.h
3. knight.py
4. templateA.html

every file has it's porpse:
1. main.c is the main program written in c.
this program for now works on the huristic method and not the brute force
wanted in the project itself. (will be rewritten and fixed soon)
- the program has a straightforward menu
-- first insert a point <A-H><1-8>
-- second enter 4 and insert the name "knight's tour" (it will create a txt file with the path)
-- thired enter 5 and agiain insert the name "knight's tour"
the program will create a new html file named path.html and will execute it in firefox
the file path.html shoes the path from the starting point given to the whole board.

2. head_main.h is the header file for main.c.
this header file defines a few prototys used in the project and will be used

3. knight.py a python program to lunch and rewrite the templateA.html as path.h
eill be excuted automatically using main.c

4. templateA.html is the templace file for the visualization of the board and the moves 
of the knight in his path.

requirements:
c
python (prefered 2.7)

lab6: main.o Executive.o BinarySearchTree.o TreeNode.o
	g++ -std=c++11 -g -Wall main.o Executive.o BinarySearchTree.o TreeNode.o -o lab6

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BinarySearchTree.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp TreeNode.h
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -std=c++11 -g -Wall -c TreeNode.cpp

clean:
	rm *.o lab6

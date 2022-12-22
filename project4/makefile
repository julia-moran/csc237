cc=g++
debugFlag=-g

tree: BinarySearchTree.o Treetest.o Term.o TermTree.o
	$(cc) -o tree TermTree.o Term.o Treetest.o BinarySearchTree.o $(debugFlag)

Treetest.o: Treetest.cpp  BinarySearchTree.h TermTree.h Term.h
	$(cc) -c Treetest.cpp $(debugFlag)

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h 
	$(cc) -c BinarySearchTree.cpp $(debugFlag)

TermTree.o: TermTree.cpp TermTree.h BinarySearchTree.h
	$(cc) -c TermTree.cpp $(debugFlag) 

Term.o: Term.cpp Term.h
	$(cc) -c Term.cpp $(debugFlag)

clean: 
	\rm -f *.o tree    

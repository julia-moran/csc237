# Source Cited:
################################################################
# Author: Dr. Spiegel
# Filename: makefile.txt
# Date: October 2, 2022
# Data retrieved: October 13, 2022
# Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/makefile.txt
################################################################
# Retrieved by:   Julia Moran
# Major:          Computer Science
# Retrieved Date: October 13, 2022
# Due Date:       October 25, 2022
# Course:         CSC237 010
# Professor Name: Dr. Spiegel
# Assignment:     #2
# Filename:       makefile
# Purpose:        Makefile to compile assignment #2
################################################################

# Citation source: This makefile is based on the file retrieved from 
# Dr. Spiegel's website at
# https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/makefile.txt
# All content was based on the file authored by Dr. Spiegel

all: app testll

CC=g++
DebugFlag=-g 

# Create the app executable

app: Term.o TermArrayList.o TermDblLinkList.o TermSTLObjList.o app.o
	$(CC) -o app Term.o TermArrayList.o TermDblLinkList.o TermSTLObjList.o app.o $(DebugFlag)

Term.o:  Term.cpp Term.h 
	$(CC) -c Term.cpp $(DebugFlag)

TermArrayList.o:  Term.h TermArrayList.cpp TermArrayList.h TermList.h 
	$(CC) -c TermArrayList.cpp $(DebugFlag)

TermDblLinkList.o: Term.h TermDblLinkList.cpp TermDblLinkList.h TermList.h DblLink.h
	$(CC) -c TermDblLinkList.cpp $(DebugFlag)

TermSTLObjList.o: Term.h TermSTLObjList.cpp TermSTLObjList.h TermList.h
	$(CC) -c TermSTLObjList.cpp $(DebugFlag)

app.o:  TermArrayList.h TermDblLinkList.h TermSTLObjList.h TermList.h app.cpp 
	$(CC) -c app.cpp $(DebugFlag)


# Create the testll executable

testll: testLL.o
	$(CC) $(DebugFlag) -o testll testLL.o

testLL.o: DblLink.h testLL.cpp
	$(CC) $(DebugFlag) -c testLL.cpp

clean:
	rm -rf *.o app app.exe testLL testLL.exe

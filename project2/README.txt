Assignment Instructions:

For this project, you will write a small software system that uses a Polynomial as in
Project 1. Its implementation will follow an object-oriented design that will give you a chance to
practice inheritance and polymorphism. It will use the TermList example on acad and the web
as a starting point. That example has a C++ array of Term implemented, somewhat, as the data
member in a TermList subclass named TermArrayList. You will add subclasses named
TermSTLObjList and TermDblLinkList to your system, the latter requiring you to implement a
doubly linked list and accompanying list iterator in a file named DblLink.h . You will choose an
STL container object as data member in the TermSTLObjList subclass.

DblLink<eltType> is a templated doubly-linked list class that will be used as the data member of
TermDblLinkList, itself a subclass of the abstract base class TermList, which contains basic
behaviors applicable to a list of Terms. Access into the linked list for traversal will be via a list
iterator wrapper class named DblLinkItr

For the second part of this assignment, write the TermSTLObjList class (with an STL container
as data member) and the TermDblLinkList class (with a DblLink object as data member and
DblLinkItr available), implementing the respective pure virtual functions (at least) inherited from
base class TermList. Create an application as follows:
  • The main menu prompts the user to select which data structure (C++ array, STL
    object, or doubly linked List; no parallel arrays this time) to use or quit. According to the
    user’s selection (an int in [1..4]), enter a submenu similar to that as the menu in the
    TermArrayList example.
  • When a data structure is selected:
    o The application’s TermList pointer ThePoly is to be instantiated to point to the object
      for the selected data type.
    o Call the readIntoList() function for that subclass (polymorphically, of course, via
      pointer ThePoly) to input the Terms from the file. It is probably easier to pass it a string.
      This call is already in app.cpp and shouldn’t require any update; it is bound
      according to what ThePoly points at.
    o Get the user’s choice from the submenu. Use polymorphism to call the correct version(s)
      of print or the () operator. The Terms must print in descending order of exponents.
  • Rewind the file during or after each call of readIntoList().
  • Each time the user exits a data structure’s submenu, reclaim the memory ThePoly
    pointed at.

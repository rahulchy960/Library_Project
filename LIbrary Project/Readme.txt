Here is the Library Handling Program implemented through C Language


Fretures :

void registration();                                   //This function is for taking members Registration in Library
void add_books();                                      //Function for Adding book details in the library
void display_ids();                                    //Function for display Registered student details
void display_all_books();                              //Function for display all book information in the library
void listbook_by_author();                             //List all book available in library with a given author
void bookname_from_isbn();                             //List the perticular book for a given ISBN
void bookcount();                                      //Display how many of a perticular book available right now
void issue_by_isbn();                                  //Book issue by a given ISBN (Registration in Library Required).It will ask for enter roll no.
void issue_by_book();                                  //Book issue by a given Book Name (Registration in Library Required).It will ask for enter roll no.
void sort_ISBN();                                      //Sort all books available in library by ISBN number



1. # The library_handle.c (RUNTIME) file is the prototye of the program without file handling and database management.
   # You can run it on console without any change (VSCode recommended).
   # All the features available in it.
   # The varible and the working is explained in the comment.
   # password knox1220


2. The main library_project.c is integrated with file handling (idcount.txt,identity.txt,bookcount.txt,books.txt)

   # The Library_Project.c file is the main program with file handling and database management 
   # The operations and data of the libraray will save in disk space
   # You dont have to change anything in the Library_Project.c file (Run in VSCode recommended).
   # All the features available in it
   # There initially some book and other details in the file 
   # Do not change anything in the files before running the program
   # If you want to Run the program from 0 you have to maintain some condition
       1. do not change the file names . if you change , then you have to change them in Library_Project.c also
       2. the idcount.txt and bookcount.txt file holds the counting of books and identities.
          So set them with a value of integer 0 only and save the file . (do not keep is two file empty)
       3. delete all the data in books.txt and identity.txt (start with empty).
       4. NOTE : one unwanted whitespace in the txt files can create a problem
   # The varible and the working is explained in the comment.
   # password knox1220


@rahulchy960
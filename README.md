### Library Management System : A Library Handler with database management in C ###

### Introduction
This C program is designed to serve as a simple library management system. It allows for the registration of library members, the addition of books to the library, displaying member information, and performing various library-related functions. The program is text-based and primarily utilizes command-line interactions.

### Functions and Features

#### 1. Member Registration (`registration()`)

This function allows library members to register by providing their name and roll number. Registered members are stored in a data structure called `idcard`. An ID number is assigned to each registered member as a unique identifier.

#### 2. Add Books to the Library (`add_books()`)

This function enables library staff to add books to the library's catalog. It collects details about each book, including the ISBN (International Standard Book Number), book name, author name, price, number of pages, stock count, and availability flag. Book information is stored in a data structure named `library`.

#### 3. Display Registered Members (`display_ids()`)

Library staff can access this function to display a list of registered members. A password ("knox1220") is required to access this feature. Once authenticated, it displays the names and roll numbers of registered members.

#### 4. Display All Books (`display_all_books()`)

This function provides a list of all books available in the library. It shows information for each book, including its ISBN, book name, author name, price, page count, stock count, and availability status.

#### 5. List Books by Author (`listbook_by_author()`)

Library staff or members can enter an author's name, and this function will list all the books written by that author. It searches the `library` data structure for matches based on the author's name.

#### 6. Find Book by ISBN (`bookname_from_isbn()`)

Users can input an ISBN number, and this function will display the book's name and author based on the ISBN. It searches the `library` data structure for a match.

#### 7. Check Available Book Count (`bookcount()`)

This function displays the stock count of each book in the library. It lists each book's name and the number of available copies.

#### 8. Issue Books (`issue_by_isbn()` and `issue_by_book()`)

Members who have registered in the library can use these functions to borrow books. They can issue books by entering the book's ISBN or its name. The program checks whether the book is available and, if so, records the issue date and provides a return date. Book stock counts are updated accordingly.

#### 9. Sort Books by ISBN (`sort_ISBN()`)

This function sorts the books in the library's catalog based on their ISBN numbers. It uses the selection sort algorithm to arrange books in ascending order.

### Program Flow

The program begins by prompting users to determine whether they are registered members. If not, they are guided through the member registration process. Once registration is complete, the program enters the library management section.

Users can choose from various menu options to interact with the library management system, including adding books, displaying book information, listing books by author, finding books by ISBN, checking available book counts, issuing books, and displaying registered member details. The program continues to run until the user decides to exit.

### Conclusion

This library management system provides a basic set of features for managing a small library. It allows for member registration, book catalog management, and various operations for library staff and members. The program includes comments to explain its functionality and structure, making it easier for users to understand and use the system. It can be further extended and improved to suit specific library management needs.

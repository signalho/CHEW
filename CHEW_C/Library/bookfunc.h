#ifndef __BOOKFUNC_H__
#define __BOOKFUNC_H__

int add_book(char (*book_name)[30], char (*auth_name)[30],
             char (*publ_name)[30], int *borrowed, int *num_total_book); 
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);
int compare(char *str1, char *str2); int borrow_book(int *borrowed);
int return_book(int *borrowed);

#endif
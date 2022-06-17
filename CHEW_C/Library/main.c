#include <stdio.h>
#include "book_function.h"

int main() {
    int user_choice;        /* 유저가 선택한 메뉴 */ 
    int num_total_book = 0; /* 현재 책의 수 */
    /* 각각책, 저자, 출판사를저장할배열생성. 책의최대개수는100 권*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30]; 
    int borrowed[100]; /* 빌렸는지 상태를 표시 */
    
    while (1) {
        printf("도서 관리 프로그램 \n"); 
        printf("메뉴를 선택하세요 \n"); 
        printf("1. 책을 새로 추가하기 \n"); 
        printf("2. 책을 검색하기 \n"); 
        printf("3. 책을 빌리기 \n"); 
        printf("4. 책을 반납하기 \n"); 
        printf("5. 프로그램 종료 \n");
        printf("당신의 선택은 : "); 
        scanf("%d", &user_choice);
        
        if (user_choice == 1) { /* 책을새로추가하는함수호출*/
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        } 
        else if (user_choice == 2) { /* 책을검색하는함수호출*/
            search_book(book_name, auth_name, publ_name, num_total_book);
        } 
        else if (user_choice == 3) { /* 책을빌리는함수호출*/ 
            borrow_book(borrowed);
        } 
        else if (user_choice == 4) { /* 책을반납하는함수호출*/ 
            return_book(borrowed);
        } 
        else if (user_choice == 5) { /* 프로그램을 종료한다. */
            break;
        } 
    }
    return 0; 
}
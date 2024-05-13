#pragma once
#include "BookNode.h"

struct BookList {
    BookNode *head;
    BookNode *tail;
    BookList();
};

void DanhSachCacSachTrongThuVien(BookList *bookList);
void ThemSach(BookList *bookList, Book book);
void NhapThemSach(BookList *bookList);
void ChinhSuaThongTinSach(BookList *bookList);
int MenuChinhSuaThongTinSach();
BookNode *BookDuaTrenISBN(BookList *bookList, string ISBN);
void ThayTheSach(BookList *&bookList, BookNode *bookNode);
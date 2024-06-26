#include <iostream>
#include "BookList.h"
#include "ReaderList.h"
#include "WriteFile.h"
#include "LendAndReturnCard.h"
#include "Statistic.h"

// khoi tao danh sach doc gia va sach
BookList *bookList = new BookList();
ReaderList* readerList = new ReaderList();

void intro() {
	cout << "Phan mem quan ly thu vien (>.<)." << endl;
	cout << "Viet boi anh Ching dep trai va em Duy gai alime nup gam giuong.\n" << endl;
}

int MainMenu() {

	// hien thong tin lua chon len man hinh
	cout << "   PHAN MEM QUAN LI THU VIEN (Ching va Duy)\n";
	cout << "     1. Quan ly doc gia" << endl;
	cout << "     2. Quan ly sach" << endl;
	cout << "     3. Lap phieu muon sach" << endl;
	cout << "     4. Lap phieu tra sach" << endl;
	cout << "     5. Thong ke" << endl;
	cout << "     6. Thoat" << endl;
	cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;

	// xu ly lenh cua nguoi dung 
	int option;
	cin >> option;
	while (option < 1 || option > 6) {
		cout << "Lenh khong hop le, vui long nhap lai: ";
		cin >> option;
	}
	return option; 
}

void ReaderManagement(int option) {
	switch (option) {
	case 1: DanhSachDocGia(readerList); break;
	case 2: NhapThemDocGia(readerList); break;
	case 3: ReaderInfoChanging(readerList); break;
	case 4: DeleteInformationReader(readerList); break;
	case 5: UserFindReaderByID(readerList); break;
	case 6: FindAllReadersWithName(readerList); break;
	}
}


void BookManagement(int option) {
	switch(option) {
	case 1: DanhSachCacSachTrongThuVien(bookList); break;
	case 2: NhapThemSach(bookList); break;
	case 3: XoaThongTinSach(bookList); break;
	case 4: ChinhSuaThongTinSach(bookList); break;
	case 5: TimKiemSachTheoISBN(bookList); break;
	case 6: FindAllBooksByName(bookList); break;
	}
}

int StatisticMenu() {
	cout << "     1.Thong ke sach\n";
	cout << "     2.Thong ke doc gia\n";
	cout << "     3.Thong ke phieu muon/tra sach\n";
	cout << "     4.Thoat\n";
	// xu ly lenh cua nguoi dung 
	int option;
	cin >> option;
	while (option < 1 || option > 4) {
		cout << "Lenh khong hop le, vui long nhap lai: ";
		cin >> option;
	}
	return option; 
}

void StatisticManagement(int option) {
	switch(option) {
	case 1: {
		BookStatisticize(bookList); cout << "\n";
		BookTypeStatisticize(bookList);
		break;
	}	
	case 2: {
		ReaderStatisticize(readerList); cout << "\n";
		ReaderStatisticizeByGender(readerList);
		break;
	}
	case 3: {
		BorrowedBookStatisticize(readerList); cout << "\n";
		LateReturnerStatisticize(readerList);
		break;
	}
	}
}

int main() {
	intro();

	InputReaderFromFile(readerList);
	InputBooksFromFile(bookList);
	
	int option; // lua chon o main menu
	int choice;	// lua chon ben trong <(")

	while (option = MainMenu()) {
		system("cls");
		switch (option) {
		case 1: {
			cout << "\tQUAN LY DOC GIA\n";
			cout << "     1. Xem danh sach doc gia trong thu vien " << endl;
			cout << "     2. Them thong tin mot doc gia " << endl;
			cout << "     3. Chinh sua thong tin doc gia " << endl;
			cout << "     4. Xoa thong tin doc gia" << endl;
			cout << "     5. tim kiem doc gia theo CMND" << endl;
			cout << "     6. Tim kiem doc gia theo ho ten" << endl;
			cout << "     7. Thoat" << endl;

			cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;
			cin >> choice;
			while (choice < 1 || choice > 7)
			{
				cout << "Vui long chon lua chon phu hop";
			}
			system("cls");
			if(choice == 7){
				continue;
			} 
			ReaderManagement(choice);
			break;
		}
		case 2: 
		{
			int choice;
			cout << "\tQUAN LY SACH\n";
			cout << "     1. Xem danh sach cac sach" << endl;
			cout << "     2. Them sach " << endl;
			cout << "     3. Xoa thong tin sach " << endl;
			cout << "     4. chinh sua thong tin sach" << endl;
			cout << "     5. tim kiem sach theo ISBN" << endl;
			cout << "     6. Tim kiem sach theo ten sach" << endl;
			cout << "     7. Thoat" << endl;
			cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;
			cin >> choice;
			while (choice < 1 || choice > 7)
			{
				cout << "Vui long chon lua chon phu hop\n";
			}
			system("cls");
			if(choice == 7) {
				continue;
			}
			BookManagement(choice);
			break;
		}
		case 3: LapPhieuMuonSach(readerList, bookList); break; 
		case 4: LapPhieuTraSach(readerList, bookList); break;
		case 5: {
			int choice = StatisticMenu();
			system("cls");
			if(choice == 4) {
				continue;
			}
			StatisticManagement(choice);
			break;
		} // viet sau // viet xong roi (chac the)
		case 6: {
			cout << "Cam on ban da su dung chuong trinh (khong ai ca)\n";
			return 0;
		}
		}
		// nguoi dung co the chon tiep tuc cac thao tac khac hoac thoat chuong trinh
		char next;
		cout << "ban co muon thuc hien thao tac khac khong? (y/n):";
		cin >> next;
		while (toupper(next) != 'Y' && toupper(next) != 'N') {
			cout << "vui long nhap N hoac Y.";
			cin >> next;
		}
		if (toupper(next) == 'N') break;
		else system("cls");
	} 
	// WriteReaderToFile(readerList);
	// WriteBooksToFile(bookList);

	delete bookList;
	delete readerList;

	return 0;
}
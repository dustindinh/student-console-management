#include<iostream>
#include<conio.h>
#include<string>
#include <iomanip>

#include "console.h";

using namespace std;

/* TÀI KHOẢNG CỦA GIÁO VIÊN / HỌC SINH */

#define TEACHER_USERNAME "trucvy"
#define TEACHER_PASSWORD "123abc!"
#define STUDENT_USERNAME "sinhvien"
#define STUDENT_PASSWORD "123123"

void callMain();
typedef struct Student {

	string MSSV;
	string hoTen;

	float ANHVAN, GDTC, NMLT, PLDC, TCC, TH_NMLT, TH_PCMT, THUD, VLDC, PCMT;
};

typedef struct StudentNode {

	Student student;
	StudentNode *next;
};
typedef struct List{

	StudentNode *head;
	StudentNode *tail;

};
List studentList;
float convertToFloat(string str) {

	if (str == "##")
		return 0.0;
	else
		return stof(str);

}
void modifyStudent(Student &sd1, Student &sd2) {

	sd1.hoTen = sd2.hoTen;

}
void printStudentList(List &l) {

	int i = 9;
	StudentNode *p = l.head;

	cout << "\nMSSV:	    HO VA TEN:			NMLT   GDTC     AVAN    PLDC    TCC   ";
	cout << " TH-NMLT  TH-PCMT  VLDC  THUD    PCMT\n\n";

	while (p != NULL) {

		cout << "0" << p->student.MSSV << "  " << p->student.hoTen << "  ";
		gotoXY(40, i);

		cout << fixed << setprecision(1) << p->student.NMLT << "     " << p->student.GDTC << "     " << p->student.ANHVAN;
		cout << "     " << p->student.PLDC << "     " << p->student.TCC << "     " << p->student.TH_NMLT;
		cout << "     " << p->student.TH_PCMT << "     " << p->student.VLDC << "     " << p->student.THUD;
		cout << "     " << p->student.PCMT;
		cout << endl;
		i++;
		p = p->next;
	}
}
StudentNode *getStudentNode(Student sd) {

	StudentNode *p = new StudentNode;

	if (p == NULL) {
		cout << "Khong du bo nho";
		exit(NULL);
	}

	p->student.MSSV = sd.MSSV;
	p->student.hoTen = sd.hoTen;

	p->student.GDTC = sd.GDTC;
	p->student.ANHVAN = sd.ANHVAN;
	p->student.NMLT = sd.NMLT;
	p->student.PLDC = sd.PLDC;
	p->student.TCC = sd.TCC;
	p->student.TH_NMLT = sd.TH_NMLT;
	p->student.TH_PCMT = sd.TH_PCMT;
	p->student.VLDC = sd.VLDC;
	p->student.THUD = sd.THUD;
	p->student.PCMT = sd.PCMT;

	p->next = NULL;

	return p;

}
void insertHead(List &l, Student sd) {

	StudentNode *p = getStudentNode(sd);

	if (p == NULL){
		cout << "Sai du lieu";
		exit(NULL);
	}

	if (l.head == NULL)
		l.head = l.tail = p;

	else {

		p->next = l.head;
		l.head = p;
	}
}
void insertTail(List &l, Student sd) {

	StudentNode *p = getStudentNode(sd);

	if (p == NULL){
		cout << "Sai du lieu";
		exit(NULL);
	}
	if (l.head == NULL)
		l.head = l.tail = p;

	else {

		l.tail->next = p;
		l.tail = p;
	}
}

void insertAfter(List &l, StudentNode *p, StudentNode *q){
	p->next = q->next;
	q->next = p;
	if (q == l.tail)
		l.tail = p;
}
void deleteHead(List &l)
{
	StudentNode *p;
	if (l.head != NULL)
	{
		p = l.head;
		l.head = l.head->next;
		delete p;
		if (l.head == NULL)
			l.tail = NULL;
	}
}
void deleteAfter(List &l, StudentNode *q)
{
	StudentNode *p;
	if (q != NULL)
	{
		p = q->next;
		if (p != NULL)
		{
			if (p == l.tail)
				l.tail = q;
			q->next = p->next;
			delete p;
		}
	}
}

int isEndOfLine(char c)
{
	return (c == '\n' || c == EOF);
}

int readLine(char * line, int max_len, FILE *fp)
{
	char c;
	int i = 0;

	while (!isEndOfLine(c = fgetc(fp)) && i < max_len - 1)
		line[i++] = c;
	line[i] = 0;

	if (i == max_len - 1)
	while ((c = fgetc(fp)) != '\n')
		;

	return i;
}
void loadStudentToList(List &l) {

	Student sd;
	char MSSV[50];
	char AVAN[50];
	char GDTC[50];
	char NMLT[50];
	char PCMT[50];
	char PL[50];
	char TCC[50];
	char THNMLT[50];
	char THPCMT[50];
	char THUD[50];
	char VLDC[50];

	FILE *fName = fopen("mssv_hoten.txt", "r");
	FILE *fAVAN = fopen("mssv_ava1.txt", "r");
	FILE *fGDTC = fopen("mssv_gdtc1.txt", "r");
	FILE *fNMLT = fopen("mssv_nmlt.txt", "r");
	FILE *fPCMT = fopen("mssv_pcmt.txt", "r");
	FILE *fPL = fopen("mssv_pl.txt", "r");
	FILE *fTCC = fopen("mssv_tcc.txt", "r");
	FILE *fTHNMLT = fopen("mssv_THNMLT.txt", "r");
	FILE *fTHPCMT = fopen("mssv_THPCMT.txt", "r");
	FILE *fTHUD = fopen("mssv_thud.txt", "r");
	FILE *fVLDC = fopen("mssv_vldc.txt", "r");

	if (fName == NULL || fNMLT == NULL)
	{
		cout << "Khong tim thay du lieu";
		exit(NULL);
	}

	while (!isEndOfLine(fgetc(fName))) {

		readLine(MSSV, 50, fName);
		readLine(AVAN, 50, fAVAN);
		readLine(GDTC, 50, fGDTC);
		readLine(NMLT, 50, fNMLT);
		readLine(PCMT, 50, fPCMT);
		readLine(PL, 50, fPL);
		readLine(TCC, 50, fTCC);
		readLine(THNMLT, 50, fTHNMLT);
		readLine(THPCMT, 50, fTHPCMT);
		readLine(THUD, 50, fTHUD);
		readLine(VLDC, 50, fVLDC);

		sd.MSSV = string(MSSV).substr(0, 10);
		sd.hoTen = string(MSSV).substr(10);


		sd.GDTC = convertToFloat(string(GDTC).substr(11));
		sd.NMLT = convertToFloat(string(NMLT).substr(11));
		sd.ANHVAN = convertToFloat(string(AVAN).substr(11));
		sd.PCMT = convertToFloat(string(PCMT).substr(11));
		sd.PLDC = convertToFloat(string(PL).substr(11));
		sd.TCC = convertToFloat(string(TCC).substr(11));
		sd.TH_NMLT = convertToFloat(string(THNMLT).substr(11));
		sd.TH_PCMT = convertToFloat(string(THPCMT).substr(11));
		sd.THUD = convertToFloat(string(THUD).substr(11));
		sd.VLDC = convertToFloat(string(VLDC).substr(11));

		insertTail(l, sd);

	}
	fclose(fName);
	fclose(fNMLT);
	fclose(fAVAN);
	fclose(fGDTC);
	fclose(fTHUD);
	fclose(fPCMT);
	fclose(fTHPCMT);
	fclose(fTHNMLT);
	fclose(fPL);
	fclose(fVLDC);
	fclose(fTCC);
}

void interChangeSort(List &sd)
{
	for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
	for (StudentNode *q = p->next; q != NULL; q = q->next)
	if (stoi(p->student.MSSV) <stoi(q->student.MSSV))
		swap(p->student, q->student);
}

void sortStudentListBySubject(List &sd, int choose)
{
	switch (choose)
	{
	case 1:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.NMLT < q->student.NMLT)
			swap(p->student, q->student);
		break;
	case 2:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.GDTC < q->student.GDTC)
			swap(p->student, q->student);
		break;
	case 3:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.ANHVAN < q->student.ANHVAN)
			swap(p->student, q->student);
		break;
	case 4:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.PLDC < q->student.PLDC)
			swap(p->student, q->student);
		break;
	case 5:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.TCC < q->student.TCC)
			swap(p->student, q->student);
		break;
	case 6:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.TH_NMLT < q->student.TH_NMLT)
			swap(p->student, q->student);
		break;
	case 7:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.TH_PCMT < q->student.TH_PCMT)
			swap(p->student, q->student);
		break;
	case 8:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.VLDC < q->student.VLDC)
			swap(p->student, q->student);
		break;
	case 9:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.THUD < q->student.THUD)
			swap(p->student, q->student);
		break;
	default:

		for (StudentNode *p = sd.head; p->next != NULL; p = p->next)
		for (StudentNode *q = p->next; q != NULL; q = q->next)
		if (p->student.PCMT < q->student.PCMT)
			swap(p->student, q->student);
		break;
	}
}

void printStudent(StudentNode *p)
{
	cout << "MSSV:	    HO VA TEN:			NMLT   GDTC     AVAN    PLDC    TCC   ";
	cout << " TH-NMLT  TH-PCMT  VLDC  THUD    PCMT\n\n";
	cout << p->student.MSSV << "  " << p->student.hoTen << "  ";

	cout << fixed << setprecision(1) << "             " << p->student.NMLT << "     " << p->student.GDTC << "     " << p->student.ANHVAN;
	cout << "     " << p->student.PLDC << "     " << p->student.TCC << "     " << p->student.TH_NMLT;
	cout << "     " << p->student.TH_PCMT << "     " << p->student.VLDC << "     " << p->student.THUD;
	cout << "     " << p->student.PCMT;
	cout << endl;
}

void searchStudent(List &l, int MSSV)
{
	StudentNode *p = l.head;
	while (p != NULL)
	{
		if (MSSV == stoi(p->student.MSSV))
		{
			printStudent(p);
			return;
		}
		p = p->next;
	}
	cout << "\nKhong tim thay sinh vien" << endl;
}
void deleteStudent(List &l, int MSSV)
{
	if (stoi(l.head->student.MSSV) == MSSV)
		deleteHead(l);
	if (l.head != NULL)
	{
		StudentNode *q = l.head;
		StudentNode *p = q->next;
		while (p != NULL)
		{
			if (stoi(p->student.MSSV) == MSSV)
			{
				deleteAfter(l, q);
				p = q->next;
			}
			q = p;
			if (p != NULL)
				p = p->next;
		}
	}
}
/*PHAN GIAO DIEN TUONG TAC*/
void printMenuTitle() {

	cout << "= = = = = = = = = = = = = = = = = = = = = =" << endl;
	cout << "=                                         =" << endl;
	cout << "=   CHUONG TRINH QUAN LY DIEM SINH VIEN   =" << endl;
	cout << "=    Copyright 2019- Huu Kien & Phan Du   =" << endl;
	cout << "=                                         =" << endl;
	cout << "= = = = = = = = = = = = = = = = = = = = = =" << endl;

}
void printMenuChoose() {

	cout << "\n [!!!] CHU Y: De co the xem duoc tat ca danh" << endl;
	cout << " sach diem cua sinh vien thi man hinh console" << endl;
	cout << " cua ban phai de o che do full screen moi co " << endl;
	cout << " the xem het vi danh sach rat nhieu diem va\n du lieu." << endl;

	cout << "\n Hay nhap so de chon tinh nang tuong ung" << endl;
	cout << "\n             1. Dang nhap" << endl;
	cout << "           2. Xem huon dan" << endl;
	cout << "        3. Thoat chuong trinh" << endl;

}
int getChoosePerm() {

	int choose;
	clrscr();
	printMenuTitle();
	cout << "\n     Ban la SINH VIEN hay GIAO VIEN" << endl;
	cout << "\n            1. Sinh Vien" << endl;
	cout << "            2. Giao Vien" << endl;
	cout << "\n            3. Tro lai\n -> ";

	cin >> choose;

	switch (choose) {
	case 1:
		return 0;
		break;
	case 2:
		return 1;
		break;
	case 3:
		return -1;
		break;
	}
}
bool isRegistedAccount(string username, string password, int perm) {

	if (perm == 1) {
		if (username == TEACHER_USERNAME) {
			if (password == TEACHER_PASSWORD) {
				return true;
			}
		}
		return false;
	}
	else {
		if (username == STUDENT_USERNAME) {
			if (password == STUDENT_PASSWORD) {
				return true;
			}
		}
		return false;
	}
	return false;
}
void printLoginMenu(int perm) {

	string username;
	string password;
	string client;
	int choose;

	clrscr();

	if (perm == 1)
		client = "GIAO VIEN";
	else
		client = "HOC SINH";

	printMenuTitle();

	cout << "\n   DANG NHAP TAI KHOANG " << client << endl;
	cout << "	 Ten dang nhap\n -> ";
	cin >> username;
	cout << "\n         Mat khau\n -> ";
	cin >> password;

	if (isRegistedAccount(username, password, perm)) {

		cout << "Dang nhap thanh cong, vui long doi . . .";
		Sleep(1500);
		clrscr();
		return;
	}
	else {
		cout << "TAI KHOANG KHONG CHINH XAC\n 1. Nhap lai\n 2. Tro lai menu\n ->" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
		default:
			printLoginMenu(perm);
			break;
		case 2:
			clrscr();
			callMain();
			break;
		}

	}
}

void printSutdentAndEdit() {

	clrscr();
	printMenuTitle();
	printStudentList(studentList);

	cout << "\n  1. Tim sinh vien theo Ma So Sinh Vien" << endl;
	cout << "   2. Chinh sua thong tin Sinh Vien" << endl;
	cout << "   3. Sap xep lai danh sach Sinh Vien" << endl;
	cout << "   4. Tro lai\n -> ";

}
void cleanArea(int a, int y) {

	gotoXY(0, y);
	for (int i = 0; i < a; i++) {

		cout << "                                                                                                                             " << endl;
	}
	gotoXY(0, 283);
}
void editStudent(List &l, int MSSV) {

	StudentNode *p = l.head;
	int choose;
	searchStudent(l, MSSV);
	while (p != NULL) {

		if (MSSV == stoi(p->student.MSSV)) {

			cout << "\nNhap vao mon muon chinnh sua:";
			cout << "\nNhap 1 de sua diem mon NMLT";
			cout << "\nNhap 2 de sua diem mon GDTC";
			cout << "\nNhap 3 de sua diem mon ANHVAN";
			cout << "\nNhap 4 de sua diem mon PLDC";
			cout << "\nNhap 5 de sua diem mon TCC";
			cout << "\nNhap 6 de sua diem mon TH_NMLT";
			cout << "\nNhap 7 de sua diem mon TH-PCMT";
			cout << "\nNhap 8 de sua diem mon VLDC";
			cout << "\nNhap 9 de sua diem mon THUD";
			cout << "\nNhap 10 de sua diem mon PCMT";
			cout << "\nNhap 11 de sua Ho Ten Sinh Vien";
			cout << "\nNhap 12 de sua Ma So Sinh Vien";
			cin >> choose;

			cout << "\n Hay nhap du lieu moi" << endl;
			switch (choose) {
			case 1:
				cin >> p->student.NMLT;
				break;
			case 2:
				cin >> p->student.GDTC;
				break;
			case 3:
				cin >> p->student.ANHVAN;
				break;
			case 4:
				cin >> p->student.PLDC;
				break;
			case 5:
				cin >> p->student.TCC;
				break;
			case 6:
				cin >> p->student.TH_NMLT;
				break;
			case 7:
				cin >> p->student.TH_PCMT;
				break;
			case 8:
				cin >> p->student.VLDC;
				break;
			case 9:
				cin >> p->student.THUD;
				break;
			case 10:
				cin >> p->student.PCMT;
				break;
			case 11:
				cin >> p->student.MSSV;
				break;
			default:
				cin >> p->student.hoTen;
			}
			cout << "\nCap Nhat lai Thong tin Sinh Vien" << endl;
			printStudent(p);

		}
		p = p->next;
	}
}

void callTeacherMenu() {

	int choose;
	bool exit = false;


	do {
		if (!exit)
			printMenuTitle();
		choose = 0;
		cout << "\n  NHAP SO DE CHON TINH NANG TUONG UNG!" << endl;
		cout << "\n  1. Xem danh sach Sinh Vien (Diem)" << endl;
		cout << "  2. Tim sinh vien theo Ma So Sinh Vien" << endl;
		cout << "  3. Chinh sua thong tin Sinh Vien" << endl;
		cout << "  4. Sap xep lai danh sach Sinh Vien" << endl;
		cout << "  5. Tro ve menu" << endl;
		cout << "\n -> ";

		cin >> choose;
		switch (choose) {
		case 1:
			exit = true;
			clrscr();
			printMenuTitle();
			printStudentList(studentList);

			cout << "\nAn bat ky de tro lai menu";
			_getch();
			break;
		case 2:
			printStudentList(studentList);
			cout << "\nNhap ma so sinh vien\n -> ";
			cin >> choose;
			searchStudent(studentList, choose);

			cout << "\nAn bat ky de tro lai menu";
			_getch();
			clrscr();
			break;
		case 3:

			printStudentList(studentList);
			cout << "Nhap vao MSSV can chinh sua thong tin" << endl;
			cin >> choose;
			editStudent(studentList, choose);

			cout << "\nAn bat ky de tro lai menu";
			_getch();
			break;
		case 4:

			if (exit){

				cleanArea(15, 290);
				gotoXY(0, 283);

			}

			cout << "\nNhap 1 de sap xep theo mon NMLT";
			cout << "\nNhap 2 de sap xep theo mon GDTC";
			cout << "\nNhap 3 de sap xep theo mon ANHVAN";
			cout << "\nNhap 4 de sap xep theo mon PLDC";
			cout << "\nNhap 5 de sap xep theo mon TCC";
			cout << "\nNhap 6 de sap xep theo mon TH_NMLT";
			cout << "\nNhap 7 de sap xep theo mon TH-PCMT";
			cout << "\nNhap 8 de sap xep theo mon VLDC";
			cout << "\nNhap 9 de sap xep theo mon THUD";
			cout << "\nNhap 10 de sap xep theo mon PCMT\n -> ";

			cin >> choose;
			sortStudentListBySubject(studentList, choose);
			exit = true;
			clrscr();
			printMenuTitle();
			cout << "\nAn bat ky de tro lai menu";
			printStudentList(studentList);
			_getch();
			break;

		default:
			break;
		}
		if (exit) {
			clrscr();
			printMenuTitle();

		}
	} while (choose != 5);
}

void callStudentMenu() {

	int choose;
	bool exit = false;

	do {
		if (!exit)
			printMenuTitle();
		choose = 0;
		cout << "\n  NHAP SO DE CHON TINH NANG TUONG UNG!" << endl;
		cout << "\n  1. Xem danh sach Sinh Vien (Diem)" << endl;
		cout << "  2. Tim sinh vien theo Ma So Sinh Vien" << endl;
		cout << "  3. Sap xep lai danh sach Sinh Vien" << endl;
		cout << "  4. Tro ve menu" << endl;
		cout << "\n -> ";

		cin >> choose;
		switch (choose) {
			case 1:
				exit = true;
				clrscr();
				printMenuTitle();
				printStudentList(studentList);

				cout << "\nAn bat ky de tro lai menu";
				_getch();
				break;
			case 2:
				cout << "\nNhap ma so sinh vien\n -> ";
				cin >> choose;
				searchStudent(studentList, choose);

				cout << "\nAn bat ky de tro lai menu";
				_getch();
				clrscr();
				break;
			case 3:

				if (exit){

					cleanArea(15, 290);
					gotoXY(0, 283);

				}

				cout << "\nNhap 1 de sap xep theo mon NMLT";
				cout << "\nNhap 2 de sap xep theo mon GDTC";
				cout << "\nNhap 3 de sap xep theo mon ANHVAN";
				cout << "\nNhap 4 de sap xep theo mon PLDC";
				cout << "\nNhap 5 de sap xep theo mon TCC";
				cout << "\nNhap 6 de sap xep theo mon TH_NMLT";
				cout << "\nNhap 7 de sap xep theo mon TH-PCMT";
				cout << "\nNhap 8 de sap xep theo mon VLDC";
				cout << "\nNhap 9 de sap xep theo mon THUD";
				cout << "\nNhap 10 de sap xep theo mon PCMT\n -> ";

				cin >> choose;
				sortStudentListBySubject(studentList, choose);
				exit = true;
				clrscr();
				printMenuTitle();
				cout << "\nAn bat ky de tro lai menu";
				printStudentList(studentList);
				_getch();
				break;

			default:
				break;
		}
		if (exit) {
			clrscr();
			printMenuTitle();

		}

	} while (choose != 4);

}

void main() {

	int choose, clientPerm;
	int MSSV, MSSV2;

	studentList.head = studentList.head = NULL;
	// LAY DU LIEU MSSV, TEN , DIEM, TAI KHOANG HOC SINH VA GIAO VIEN

	loadStudentToList(studentList);
	printMenuTitle();
	printMenuChoose();

	cout << " -> ";

	cin >> choose;

	getperm:switch (choose) {
	case 1:
		switch (clientPerm = getChoosePerm()) {
		case 1:
		case 0:
			break;
		default:
			clrscr();
			main();
			break;
		}
		break;
	case 2:
		system("start help.pdf");
		main();
		break;
	case 3:
		exit(NULL);
		break;
	default:
		main();
		break;
	}

	printLoginMenu(clientPerm);

	switch (clientPerm) {

	case 1:
		callTeacherMenu();
		break;
	case 2:
	default:
		callStudentMenu();
		break;
	}
	clrscr();
	goto getperm;
	_getch();

}
void callMain() {
	main();
}

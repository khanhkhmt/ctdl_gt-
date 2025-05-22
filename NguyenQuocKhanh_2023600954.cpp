# include <bits/stdc++.h> 
#include <iomanip>
using namespace std ;

struct SP {
	char mahang[10] ;
	char tenhang[20] ;
	char dvtinh[20] ;
	int dongia ;
	int soluong ;
};

struct Node {
	SP data ;
	Node *next ;
};

typedef struct Node* tro ;
tro L = NULL ;

void nhapsp(SP& data) {
	cout << "nhap ma hang: " ; 	fflush(stdin) ; gets(data.mahang) ;
	cout << "nhap ten hang: " ;	fflush(stdin) ; gets(data.tenhang) ;
	cout << "nhap DV tinh: " ;	fflush(stdin) ; gets(data.dvtinh) ;
	cout << "nhap don gia: " ;	cin >> data.dongia ;
	cout << "nhap so luong: " ;	cin >> data.soluong ;
}

void insp (SP data) {
	cout << setw(15) << data.mahang << setw(15) << data.tenhang << setw(15) << data.dvtinh << setw(15) << data.dongia << setw(15) << data.soluong << setw(15) << data.dongia * data.soluong << endl ;
	
}
bool Empty (tro L ) {
	if (L== NULL) return 1 ;
	else return 0 ;
}
bool Create (tro& L) {
	if (Empty (L)) {
		L = new Node ;
		return 1 ;
	}
	else return 0 ;
}
void Nhap (tro& L) {
	string tieptuc ;
	tro prev = L ;
	tro current ;
	while (1) {
		SP data ;
		nhapsp (data) ;
		if (Empty(L)){
			Create(L) ;
			L -> data = data ;
			L -> next = NULL ;
			prev = L ;
		}
		else {
			current = new Node ;
			current -> data = data ;
			current -> next = NULL ;
			prev -> next = current ;
			prev = current ;
		}
		cout << "tiep tuc ? C/K: " ; cin >> tieptuc ;
		cin.ignore() ;
		if (tieptuc[0] == 'K') return ;
	}
}
void XuatList(tro L) {
	tro Current = L;
	int i = 1;
	
	while (Current != NULL) {
		cout << setw(10) << i++;
		insp(Current->data);
		Current = Current->next;
	}
}
void timmax (tro L) {
	int max = L -> data.soluong ;
	tro current = L-> next ;
	while (current != NULL) {
		if (current -> data.soluong > max) {
			max = current -> data.soluong ;
		}
		current = current -> next ;
	}
	current = L ;
	while (current != NULL) {
		if (current -> data.soluong == max) {
			insp (current->data ) ;
		}
		current = current -> next ;
	}
}
void timmin (tro L) {
	int min = L ->data.soluong ;
	tro current = L->next ;
	while (current != NULL) {
		if (current->data.soluong< min) {
			min = current->data.soluong ;
		}
		current = current->next ;
	}
	current = L ;
	while (current != NULL) {
		if (current->data.soluong == min) {
			insp (current->data) ;
		}
		current = current->next ;
	}
}
void thaythe (tro& L) {
	tro current = L;
	while (current != NULL) {
		if (strcmp(current->data.tenhang , "kk")==0) {
			strcpy (current->data.tenhang , "VO") ;
		}
		current = current->next ;
	}
	current = L ;
	while (current != NULL ) {
		insp (current->data) ;
		current = current->next ;
	}
	
}
int dem (tro L) {
	int max = L->data.dongia ;
	tro current = L->next ;
	while (current != NULL) {
		int temp = current->data.dongia ;
		if (temp > max) {
			max = temp ;
		}
		current = current->next ;
	}
	current = L ;
	int count = 0 ;
	while (current != NULL) {
		if (current->data.dongia == max) count++ ;
		current = current->next ;
	}
	return count ;
}
void xoa (tro& L , int k) {
	tro prev = NULL ;
	tro current = L; 
	int i = 1 ;
	while (current->next != NULL && i < k) {
		prev = current ;
		current = L->next ;
		i++ ;
	}
	if ((i < k || prev == NULL) && k!=1) {
		cout << "khong ton tai vi tri can xoa!" << endl ;
	}
	if (k==1){
		L = current->next;
	}
	else{
		prev->next = current->next;
	}
	delete current;
}
void chen(tro& L, int k) {
	if (Empty(L)) return;
	tro prev = NULL;
	tro current = L;
	int i=1;
	while(current->next!=NULL && i<k){
		prev = current;
		current = current->next;
		i++;
	}
	if ((prev == NULL || i<k) && k!=1){
		return;
	}
	tro newn = new Node;
	nhapsp(newn->data);
	newn->next = NULL;
	if (k == 1){
		L = newn;
		newn->next=current;
	}
	else{
	prev->next = newn;
	newn->next = current;
	}
}
void sapxep (tro& L) {
	tro current = L;
	tro check = NULL;
	while(current!=NULL){
		tro p=L;
		while(p->next!=check){
			float tmp = p->data.dongia*p->data.soluong;
			float tmp2 = p->next->data.dongia*p->next->data.soluong;
			if (tmp>tmp2){
				swap(p->data,p->next->data);
			}
			p = p->next;
		}
		check = p;
		current = current->next;
	}
}
int main () {
	Nhap (L) ;
	XuatList (L) ;
	cout << "san pham max la: " << endl ;
	timmax (L) ;
	cout << "san pham min la: " << endl ;
	timmin (L) ;
	cout << "sau thay the: " << endl ;
	thaythe (L) ; 
	cout << "so hang co don gia cao nhat: " << dem(L) << endl ;
	int k ; cout << "nhap vi tri can xoa: " ; cin >> k ; 
	cout << "sau khi xoa: " << endl ;
	xoa(L, k) ;
	XuatList (L) ;
	int ch ; cout << "nhap vi tri can chen: " ; cin >> ch ;
	chen(L, ch) ;
	XuatList(L) ;
	cout << "day sau sap xep" << endl ;
	sapxep(L) ;
	XuatList(L) ;
}

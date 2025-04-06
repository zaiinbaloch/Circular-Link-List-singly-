#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class CircularLinklist {
	Node* head = NULL;
	Node* tail = NULL;
public:
	void insertathead(int d) {
		Node* node = new Node;
		node->data = d;
		if (head == NULL) {
			head = tail = node;

		}
		else {
			node->next = head;
			head = node;
			tail->next = head;
		}
	}
	void insertattail(int d) {
		Node* node = new Node;
		node->data = d;
		node->next = head;
		if (head == NULL) {
			head = tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		
	}
	void insertattarget(int d, int target) {
		Node* node = new Node;
		node->data = d;
		Node* temp = head;
		if (head == NULL) {
			cout << "Link list is empty initilize the list first by selecting other options\n";
			return;
		}
		if (head->data == target) {
			node->next = head->next;
			head->next = node;
			return;
		}
		temp = temp->next;
		while (temp != head && temp->data != target) {
			temp = temp->next;
		}
		if (temp->data == target) {
			node->next = temp->next;
			temp->next = node;
		}
		if (temp == tail) {
			node->next = head;
			temp->next = node;
		}
		else if (temp->data != target) {
			cout << "target not found \n";
			delete node;
			return;
		}
	}

	void delnode(int target) {
		Node* temp;
		temp = head;
		Node* prev = NULL;
		if (head == NULL) {
			cout << "Link list is empty \n";
			return;
		}
		if (head->data == target) {
			head = head->next;
			tail->next = head;
			temp->next = NULL;
			delete temp;
			return;
		}
		while (temp->data != target) {
			prev = temp;
			temp = temp->next;
		}
		if (temp->data == target) {
			prev->next = temp->next;
		}
		else if (temp == tail) {
			prev->next = head;
			tail = prev;
			temp->next=NULL;
		}
		else {
			cout << "target not found \n";
		}
		delete temp;
	}


	void print() {
		Node* temp;
			temp = head;
			if (head == NULL) {
				cout << "Link list is empty at the moment initilize the list first \n";
				return;
			}
		cout << temp->data << " -> ";
		
		if (temp->next == tail->next) {
			cout <<temp->data << endl;
			return;
		}
		temp = temp->next;
		while (temp!= head) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << temp->data << " -> Same values will repeat" << endl;
	}
};

int main() {
	CircularLinklist l;
	int a = 0, t = 0;
	char c, C, ch;
	do {
		cout << "Enter A to insert at head\n"
			<< "Enter B to insert at tail\n"
			<< "Enter C to insert at target\n"
			<< "Enter D to delete a target" << endl;
		cin >> c;
		switch (c) {
		case 'A':
			do {
				cout << "Current list : ";
				l.print();

				cout << "Enter a value to be inseted from head : ";
				cin >> a;
				l.insertathead(a);
				system("cls");
				cout << "Updated list : ";
				l.print();
				cout << "Enter Y to continue or N to stop : ";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			break;
		case 'B':
			do {
				cout << "Current list : ";
				l.print();

				cout << "Enter a value to be inseted from tail : ";
				cin >> a;
				l.insertattail(a);
				system("cls");
				cout << "Updated list : ";
				l.print();

				cout << "Enter Y to continue or N to stop : ";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			break;
		case 'C':
			do {
				cout << "Current list : ";
				l.print();

				cout << "Enter a value to be inseted at target : ";
				cin >> a;
				cout << "Enter a target value after which you want to insert in list : ";
				cin >> t;
				l.insertattarget(a, t);
				system("cls");
				cout << "Updated list : ";
				l.print();

				cout << "Enter Y to continue or N to stop : ";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			break;
		case 'D':
			do {
				cout << "Current list : ";
				l.print();

				cout << "Enter a target value which you want to delete from list : ";
				cin >> t;
				l.delnode( t);
				system("cls");
				cout << "Updated list : ";
				l.print();

				cout << "Enter Y to continue or N to stop : ";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			break;
		default:
			break;
		}
		cout << "Enter Y to return to main menu or N to exit : ";
		cin >> C;
	} while (C == 'y' || C == 'Y');


	return 0;
}

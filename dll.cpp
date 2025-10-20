// COMSC-210 | Midterm #2 | Diksha Tara Natesan
// IDE used: Vim/Terminal


#include <iostream>
using namespace std;
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
class Customer{
	private:
		string name;
		bool isVIP;
	public:
		Customer(){};
		Customer(string n){
			name = n;
			isVIP = false;
			prob = rand() % 100 + 1  // returns random number 1-100
			if (prob <= 10) {
    				isVIP = true;
			}
		}
		Customer(string n, bool vip){
			name = n;
			isVIP = vip;
		}
		string getName()	{return name;}
		bool isVIP()		(return isVIP;}
		void print
};

class DoublyLinkedList {
	private:
		struct Node {
			int data;
			Node* prev;
			Node* next;
			Node(int val, Node* p = nullptr, Node* n = nullptr) {
				data = val;
				prev = p;
				next = n;
			}
		};
		Node* head;
		Node* tail;
	public:
		DoublyLinkedList() { head = nullptr; tail = nullptr; }
		void insert_after(int value, int position) {
			if (position < 0) {
				cout << "Position must be >= 0." << endl;
				return;
			}
			Node* newNode = new Node(value);
			if (!head) {
				head = tail = newNode;
				return;
			}
			Node* temp = head;
			for (int i = 0; i < position && temp; ++i)
				temp = temp->next;
			if (!temp) {
				cout << "Position exceeds list size. Node not inserted.\n";
				delete newNode;
				return;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			if (temp->next)
				temp->next->prev = newNode;
			else
				tail = newNode;
			temp->next = newNode;
		}
		void delete_val(int value) {
			if (!head) return;
			Node* temp = head;
			while (temp && temp->data != value)
				temp = temp->next;
			if (!temp) return;
			if (temp->prev)
				temp->prev->next = temp->next;
			else
				head = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			else
				tail = temp->prev;
			delete temp;
		}
		void delete_pos(int pos) {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			if (pos == 1) {
				pop_front();
				return;
			}
			Node* temp = head;
			for (int i = 1; i < pos; i++){
				if (!temp) {
					cout << "Position doesn't exist." << endl;
					return;
				}
				else
					temp = temp->next;
			}
			if (!temp) {
				cout << "Position doesn't exist." << endl;
				return;
			}
			if (!temp->next) {
				pop_back();
				return;
			}
			Node* tempPrev = temp->prev;
			tempPrev->next = temp->next;
			temp->next->prev = tempPrev;
			delete temp;
		}
		void push_back(int v) {
			Node* newNode = new Node(v);
			if (!tail)
				head = tail = newNode;
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
		}
		void push_front(int v) {
			Node* newNode = new Node(v);
			if (!head)
				head = tail = newNode;
			else {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
		}
		void pop_front() {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			Node * temp = head;
			if (head->next) {
				head = head->next;
				head->prev = nullptr;
			}
			else
				head = tail = nullptr;
			delete temp;
		}
		void pop_back() {
			if (!tail) {
				cout << "List is empty." << endl;
				return;
			}
			Node * temp = tail;
			if (tail->prev) {
				tail = tail->prev;
				tail->next = nullptr;
			}
			else
				head = tail = nullptr;
			delete temp;
		}
		~DoublyLinkedList() {
			while (head) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
		void print() {
			Node* current = head;
			if (!current) {
				cout << "List is empty." << endl;
				return;
			}
			while (current) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
		void print_reverse() {
			Node* current = tail;
			if (!current) {
				cout << "List is empty." << endl;
				return;
			}
			while (current) {
				cout << current->data << " ";
				current = current->prev;
			}
			cout << endl;
		}
};
int main() {
	//store opens message maybe add int for time periods, 20 total times
	//create DLL for the queue with 5 customers using the external file of names
	//need to code the probabilites into the next time periods (large loop/method that has each probability?
	//put out code in the chunks of the minutes, not by each customer operation
	//
	cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
		return 0;
}

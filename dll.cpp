// COMSC-210 | Midterm #2 | Diksha Tara Natesan
// IDE used: Vim/Terminal


#include <iostream>
#include <fstream>
using namespace std;
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
class Customer{
	private:
		string name;
		bool isVIP;
	public:
		Customer(){
			name = "BLANK";
			isVIP = false;
                        int prob = rand() % 100 + 1;  // returns random number 1-100
                        if (prob <= 10) {
                                isVIP = true;
                        }
		}
		Customer(string n){
			name = n;
			isVIP = false;
			int prob = rand() % 100 + 1;  // returns random number 1-100
			if (prob <= 10) {
    				isVIP = true;
			}
		}
		Customer(string n, bool vip){
			name = n;
			isVIP = vip;
		}
		string getName()	{return name;}
		bool VIP()		{return isVIP;}
		void print(){
			cout << name;
			if (isVIP)
				cout << " (VIP)";
		}
};

class DoublyLinkedList {
	private:
		struct Node {
			Customer* data;
			Node* prev;
			Node* next;
			Node(Customer* val, Node* p = nullptr, Node* n = nullptr) {
				data = val;
				prev = p;
				next = n;
			}
		};
		Node* head;
		Node* tail;
	public:
		DoublyLinkedList() { head = nullptr; tail = nullptr; }
/*		void insert_after(Customer value, int position) {
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
		void delete_val(Customer value) {
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
*/		void push_back(Customer* v) {
			Node* newNode = new Node(v);
			if (!tail)
				head = tail = newNode;
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			//output the operation when customer joins the line
			cout << "\t";
			newNode->data->print();
			cout << " joins the line" << endl;
		}
		void push_front(Customer* v) {
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
			cout << "\tResulting line:" << endl;
			while (current) {
				cout << "\t\t";
				current->data->print();
				cout << endl;
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
			cout << "\tResulting line:" << endl;
			while (current) {
				cout << "\t\t";
				current->data->print();
				cout << endl;
				current = current->prev;
			}
			cout << endl;
		}
};

//randInt99() takes no arguments and creates a number between 0-98 to choose a random name
//returns generated random num
int randInt99();
void operation(DoublyLinkedList list, array<string> names);

int main() {
	srand(time(0));	//for the rand() to reset
	ifstream fin("names.txt");
	array<string,99> names;
	int count = 0;
	if (fin.good( )) {
        	string line;
		while (getline(fin, line) && count < names.size()) {
            		names[count] = line;
            		count += 1;
        	}
	}
        fin.close( ); // close the file

	//create a 

	int period = 1;
	DoublyLinkedList list;
	for(int i = 0; i < 5; i++){
		Customer* a = new Customer(names[randInt99()]);
		list.push_back(a);
	}
	list.print();
	//store opens message maybe add int for time periods, 20 total times
	cout << "Store opens:" << endl;
	//create DLL for the queue with 5 customers using the external file of names
	//need to code the probabilites into the next time periods (large loop/method that has each probability?
	//put out code in the chunks of the minutes, not by each customer operation
	//
	cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
		return 0;
}

int randInt99(){
	return rand() % 98;
}

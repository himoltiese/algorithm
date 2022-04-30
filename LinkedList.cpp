#include <iostream>

using namespace std;
class Node {
public :
	class Node* next;
	int data;
};

class List {
private:
	class Node* head;// 기준점 malloc느낌 일단 heap부분에 생성 링크드리스트 쓸려면 heap에 메모리를 설정해줘야함
public:
	class Node* tempWant;
	List(); // 생성자는 기준을 만들어줌
	~List();
	void CreatNewNode(int x);
	void Insert(int x,int index);
	void PrintAll() {
		tempWant=head;
		while (tempWant->next != NULL) {
			cout << tempWant->data << "->";
			tempWant = tempWant->next;
		}
		cout << tempWant->data;
	}
};

List::List() { // heap부분에 메모리 할당해줌
	head = NULL; // 기준점 생성
}
List::~List(){} // 제거자 heap부분에 차지하는 메모리를 제거함

void List::CreatNewNode(int x) {
	class Node* temp = new Node;
	temp->next = head; // pointer ; (*temp).next = head;이므로 temp값이 주소아님 head의 주소를 가르키게해야함
	temp->data = x; // data값 생성 넣어줌 (*temp).data = x;라는 소리인데 그 temp가 포인터이므로 거기를 가르키는 data 값이 x라는소리
	head = temp; // 이전의 주소를 temp로 옮겨줌 그래야하는게 맞음 이전주소가 temp로 들어가서 새로운 head가 만들어지는것이므로
}

void List::Insert(int x,int index) {
	class Node* preTemp = head;
	class Node* insertValue = new Node;
	class Node* temp = new Node;
	for (int i = 0; i < index; i++) {
		preTemp = preTemp->next;
	}
	temp = preTemp->next;
	preTemp->next = insertValue;
	insertValue->next = temp;
	insertValue->data = x;
}

int main() {
	List list;
	list.CreatNewNode(30);
	list.CreatNewNode(40);
	list.CreatNewNode(50);
	list.CreatNewNode(30);
	list.CreatNewNode(40);
	list.CreatNewNode(50);
	list.Insert(7, 1);
	list.Insert(8, 3);
	list.PrintAll();
}
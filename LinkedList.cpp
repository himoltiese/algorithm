#include <iostream>

using namespace std;
class Node {
public :
	class Node* next;
	int data;
};

class List {
private:
	class Node* head;// ������ malloc���� �ϴ� heap�κп� ���� ��ũ�帮��Ʈ ������ heap�� �޸𸮸� �����������
public:
	class Node* tempWant;
	List(); // �����ڴ� ������ �������
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

List::List() { // heap�κп� �޸� �Ҵ�����
	head = NULL; // ������ ����
}
List::~List(){} // ������ heap�κп� �����ϴ� �޸𸮸� ������

void List::CreatNewNode(int x) {
	class Node* temp = new Node;
	temp->next = head; // pointer ; (*temp).next = head;�̹Ƿ� temp���� �ּҾƴ� head�� �ּҸ� ����Ű���ؾ���
	temp->data = x; // data�� ���� �־��� (*temp).data = x;��� �Ҹ��ε� �� temp�� �������̹Ƿ� �ű⸦ ����Ű�� data ���� x��¼Ҹ�
	head = temp; // ������ �ּҸ� temp�� �Ű��� �׷����ϴ°� ���� �����ּҰ� temp�� ���� ���ο� head�� ��������°��̹Ƿ�
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
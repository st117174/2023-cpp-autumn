#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	~LinkedList()
	{
		dispose;
	}
	int Length()
	{
		int count = 0;
		Node* cur = head;
		while (cur != nullptr)
		{
			cur = cur->next;
			count++;
		}
	}
	bool IsEmpty()
	{
		if (head = nullptr)
		{
			return true;
		}
		return false;
	}

	//вставляет элемент data на позицию index
	void Insert(int index, int data)
	{

	}

	void PushHead(int data)
	{

	}

	void PushTail(int data);

	//извлекает головной элемент
	int PopHead();

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index);
	int PopTail();

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index);
	void swap(int ia, int ib);
	void sort();

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{

	}
		;

private:
	void dispose();

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node)
	{}

	void InsertNode(int index, Node* node)
	{}

	Node* ExtractNode(int index)
	{}

	bool IndexValid(int index)
	{}

	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}
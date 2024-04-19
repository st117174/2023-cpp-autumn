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
		Node* node = new Node(data);
		InsertNode(index, node);
	}

	void PushHead(int data)
	{
		Node* node = new Node(data);
		InsertNode(0, data);
	}

	void PushTail(int data);
	{
		Node* node = new Node(data);
		InsertNode(Length(), data);
	}

	//извлекает головной элемент
	int PopHead()
	{
		return PopData(ExtractNode(0));
	}

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index)
	{
		return PopData(ExtractNode(index));
	}


	int PopTail()
	{
		return PopData(ExtractNode(index));
	}

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index)
	{
		Node* cur = head;
		for (int i = 0, i < index&& cur != nullptr; ++i)
		{
			cur = cur->next;
		}
		if (cur != nullptr)
		{
			return cur->data;
		}
		else
		{
			return 0;
		}
	}

	void Swap(int ia, int ib)
	{
		if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
		{
			return;
		}
		if (ia > ib)
		{
			return swap(ib, ia)
		}
		Node* na = ExtractNode(ia);
		Node* nb = Excract(ib - 1);
		if (na = nullptr || nb == nullptr)
		{
			return;
		}
		InsertNode(ia, nb);
		InsertNode(ib, na);
	}

	void sort()
	{
		for (int i = Length() - 1; i >= 0; --i)
		{
			for (int j = 0, j < i; ++j)
			{
				if Data(j) > Data(j + 1) {
					Swap(j, j + 1)
				}
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
		Node* cur = list.head;
		while (cur != nullptr)
		{
			stream << *cur << " ";
			cur = cur->next;
		}
		return stream;
	};

private:
	void dispose()
	{
		while (head != nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int res = node->data;
		delete node;
		return res;
	}

	void InsertNode(int index, Node* node)
	{
			if (index <= 0 || head == nullptr)
			{
				node->next = head;
				head = node;
			}
			else
			{
				Node* cur = head;
				for (int i = 0; i < index - 1 && cur->next != nullptr; ++i)
				{
					cur = cur->next;
				}
				node->next = cur->next;
				cur->next = node;
			}
	}

	Node* ExtractNode(int index)
	{
		If(IndexValid(index))
		{
			if (index == 0)
			{
				Node* tmp = head;
				head = head->next;
				return tmp;
			}
			Node* cur = head;
			for (int i = 0; i < index - 1; ++i)
			{
				cur = cur->next;
			}
			Node* tmp = cur->next;
			cur->next = tmp->next;
			return tmp;
		}
		return nullptr;
	}

	bool IndexValid(int index)
	{
		if (index >= 0)
		{
			return index < Length();
		}
		return false;
	}

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
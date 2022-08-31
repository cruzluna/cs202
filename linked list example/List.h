using namespace std;

struct Node
{
	int data;
	Node* next;

	//NODE 
	Node(int data) { this->data = data; next = nullptr; }
};

class List
{
	Node* head;

public:
	List() {
		head = nullptr;
	};
	/*~List()
	{
		current = head->next;
		prev = head;
		while(current != nullptr)
		{
			delete prev;
			prev = current;//cannot do prev = prev b/c seg fault
			current = current->next;//move pointer
		}
		delete prev; //delete last node


		alternate Way:

		~List()
		{	//recursive for Singly linked list
			delete head;/technically a function call
		}

		~Node()
		{
			if(next!=nullptr)//base case
			{
				delete next;//will eventually delete the head
				//^^reduction operator
			}
		}
	} */
	Node* getHead() const { return head; }
	void Insert(int new_data);
	Node* Lookup(int object);
	void Deletion(int object);

	//Recursive versions
	void RecursiveInsert(int new_data, Node* current);
	Node* RecursiveLookup(int object, Node* current);
	void RecursiveDeletion(int object, Node* current, Node* prev);

	void insertInOrder(int object);

	void print();
	int getSize();
	void sort();
};


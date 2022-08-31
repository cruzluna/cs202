template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node<T>(T data) { this->data = data; next = NULL; }
};

template <class T>
class List
{
	Node<T>* head;

public:
	List();
	void Insert(T new_data);
	Node<T>* Lookup(T object);
	void Deletion(T object);
};


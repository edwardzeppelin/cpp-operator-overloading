#include "stack.h"

using namespace std;

stack::stack(int max) {
	top = nullptr;
	size = 0;
	maxsize = max;
}

stack::stack() {
	top = nullptr;
	size = 0;
	maxsize = 10;
}

stack::~stack() {
	while (!isempty()) {
		del();
	}
}

void stack::add(int x) {
	if (isfull()) {
		cout << "Stack Overflow\n";
		exit(EXIT_FAILURE);
	}

	node* newnode = new node;
	newnode->setdata(x);
	newnode->next = top;
	top = newnode;
	size = size + 1;

}

void stack::del() {
	if (isempty()) {
		cerr << "Stack is empty. Can't delete." << endl;
		return;
	}
	node* temp = top;
	top = top->next;
	delete temp;
	size = size - 1;
}

int stack::peek() {
	if (isempty()) {
		cerr << "Stack is empty. Can't peek." << endl;
		return -1;
	}
	return top->getdata();
}

bool stack::isempty() const {
	return top == nullptr;
}

bool stack::isfull() {
	return size >= maxsize;
}

ostream& operator<<(ostream& os, const stack& st) {
	node* curr = st.top;
	while (curr != nullptr) {
		os << curr->getdata() << " ";
		curr = curr->next;
	}
	return os;
}

istream& operator>>(istream& is, stack& st) {
	int val;
	is >> val;
	st.add(val);
	return is;
}

stack& stack::operator=(const stack& other) {
	if (this != &other) {
		while (!isempty()) del();

		stack temp(other.maxsize);
		node* curr = other.top;
		while (curr != nullptr) {
			temp.add(curr->getdata());
			curr = curr->next;
		}

		while (!temp.isempty()) {
			add(temp.peek());
			temp.del();
		}
	}
	return *this;
}

bool stack::operator==(const stack& other) const {
	if (size != other.size)
		return false;

	node* curr1 = top;
	node* curr2 = other.top;

	while (curr1 != nullptr && curr2 != nullptr) {
		if (curr1->getdata() != curr2->getdata())
			return false;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	return curr1 == nullptr && curr2 == nullptr;
}

bool stack::operator<(const stack& other) const {
	return size < other.size;
}

bool stack::operator>(const stack& other) const {
	return size > other.size;
}

bool stack::operator!() const {
	return isempty();
}

/*stack operator-(const stack& stack1, const stack& stack2) {
	stack result;

	node* curr1 = stack1.top;
	node* curr2 = stack2.top;
	while (curr1 != nullptr && curr2 != nullptr) {
		result.add(curr1->getdata() - curr2->getdata());
		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	stack reversedResult;
	while (!result.isempty()) {
		reversedResult.add(result.peek());
		result.del();
	}

	return reversedResult;
}*/

stack& stack::operator-=(const stack& other) {
	node* current = top;
	node* otherCurrent = other.top;
	while (current != nullptr && otherCurrent != nullptr) {
		current->setdata(current->getdata() - otherCurrent->getdata());
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
	return *this;
}

stack& stack::operator/=(const stack& other) {
	node* current = top;
	node* otherCurrent = other.top;
	while (current != nullptr && otherCurrent != nullptr) {
		if (otherCurrent->getdata() == 0) {
			cout << "Error: Division by zero" << endl;
			return *this;
		}
		current->setdata(current->getdata() / otherCurrent->getdata());
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
	return *this;
}

/*stack stack::operator/(const stack& otherStack) {
	stack result;
	node* temp1 = top;
	node* temp2 = otherStack.top;

	while (temp1 != nullptr && temp2 != nullptr) {
		result.add(temp1->getdata() / temp2->getdata());
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	stack reversedResult;
	while (!result.isempty()) {
		reversedResult.add(result.peek());
		result.del();
	}

	return reversedResult;
}*/

stack stack::operator/(int divisor) {
	stack result;
	node* temp = top;

	while (temp != nullptr) {
		// Проверяем, что divisor не равен нулю, чтобы избежать деления на ноль
		if (divisor != 0) {
			// Добавляем результат деления элемента стека на divisor в результирующий стек
			result.add(temp->getdata() / divisor);
		}
		else {
			result.add(0);
		}
		temp = temp->next;
	}

	// Нет необходимости обращаться стеку в обратном порядке,
	// поэтому просто возвращаем результат
	return result;
}

stack operator-(const stack& stack1, const int x) {
	stack result;

	node* curr1 = stack1.top;
	while (curr1 != nullptr) {
		result.add(curr1->getdata() - x);
		curr1 = curr1->next;
	}

	stack reversedResult;
	while (!result.isempty()) {
		reversedResult.add(result.peek());
		result.del();
	}

	return reversedResult;
}
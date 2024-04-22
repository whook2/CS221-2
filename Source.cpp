// Will Hooker
// CS221 Programming Assignment 2
// This program creates a linked list along with a few operations for the list, populates it with predetermined values, and then tests manipulating the list
#include <iostream>

using namespace std;

struct Node {
		int data;
		Node* next;
	};

class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = NULL;
		}

		void PutItem(int newNum) {
			Node* newNode = new Node;
			newNode->data = newNum;
			newNode->next = NULL;

			if (head == NULL) {
				head = newNode;
			}
			else {
				Node* temp = head;
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = newNode;
			}
		}
		void DeleteItem(int num) {
			Node* temp = head;

			while (temp->next->data != num)
				temp = temp->next;

			if (temp->next->next == NULL) {
				temp->next = NULL;
			}
			else {
				temp->next = temp->next->next;
			}
		}
		void Print() {
			if (head == NULL) cout << "The list is empty" << endl;
			Node* temp = head;

			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
			}
		bool IsFull() {
			Node* location;
			try
			{
				location = new Node;
				delete location;
				return false;
			}
			catch (bad_alloc exception) 
			{
				return true;
			}
		}
		int GetLength() {
			int count = 0;
			Node* temp = head;

			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			return count;
		}
		void MakeEmpty() {
			Node* temp = head;
			

			do {
				Node* next = temp->next;
				delete temp;
				temp = next;
			} 
			while (temp != NULL);
			head = NULL;
		}
};



int main() {

	LinkedList List; //creating the list

	for (int i = 5; i <= 25; i += 5) { //using a for loop to add the values to the list. it calls the PutItem function for each value represented by i
		List.PutItem(i);
	};

	cout << "Elements of the linked list: ";
	List.Print(); //calls the print function to print the list

	cout << "Deleting 15 from the list." << endl;
	List.DeleteItem(15); //calls the DeleteItem function to delete the value 15 from the list
	
	cout << "Elements of the linked list: ";
	List.Print(); //calls the print function to print the list
	
	cout << "Is the linked list full? "; //calls the IsFull function to check if the list is full and prints the result
	if (List.IsFull() == false) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	cout << "Length of the linked list: " << List.GetLength() << endl; //calls the GetLength function and prints the result
	
	cout << endl << "Emptying the list." << endl;
	List.MakeEmpty(); //calls the MakeEmpty function to empty the list, and then calls the Print function to check if the list was emptied
	List.Print();

	return 0;
}


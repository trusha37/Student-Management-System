#include <bits/stdc++.h>
using namespace std;

//class node containing student info fields
class Node {
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
	Node* left;
    Node* right;
};

// creating a head node
Node* head = new Node();

// to check if a roll no. already exists or not
// returns true is exists
//else returns false
bool check(int x)
{
	//
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	//
	while (t != NULL) {
		if (t->roll == x)
			return true;
		t = t->right;
	}

	return false;
}

// to insert a new record
void Insert_Record(int roll, string Name, string Dept, int Marks)
{
	// check if roll no. already exists
	if (check(roll)) {
		cout << "Student with this "<< "record Already Exists\n";
		return;
	}

	// creating new node and storing data
	Node* t = new Node();
	t->roll = roll;
	t->Name = Name;
	t->Dept = Dept;
	t->Marks = Marks;
	t->left = NULL;
    t->right=NULL;

	// if list if empty then create head node
	if (head == NULL) {
		head = t;
        cout<<"Head created"<<endl;
	}
	// insert at beginning
    else if(head->roll >= t->roll){
        t->right=head;
        head->left=t;
        t->left=NULL;
        head=t;
    }

	// insert at middle and end
	else {
		Node* c = head;
		while (c->right != NULL && c->right->roll < t->roll) {
			c = c->right;
		}
		// insert at end
        if(c->right==NULL)
		{
            c->right=t;
            t->left=c;
        }
		// insert at middle
        else
        {
            t->right=c->right;
            c->right->left=t;
            c->right=t;
            t->left=c;
        }

	}

	cout << "Record Inserted Successfully\n";
}

// function to search a record
void Search_Record(int roll)
{
	// if list is empty
	if (!head) {
		cout << "No such Record "<< "Available\n";
		return;
	}

	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
				cout << "Roll Nmuber\t"
					<< p->roll << endl;
				cout << "Name\t\t"
					<< p->Name << endl;
				cout << "Department\t"
					<< p->Dept << endl;
				cout << "Marks\t\t"
					<< p->Marks << endl;
				return;
			}
			p = p->right;
		}

		if (p == NULL)
			cout << "No such Record "<< "Available\n";
	}
}

// function to delete a record
int Delete_Record(int roll)
{
	Node* t = head;
	Node* p = NULL;

	// delete at beginning
	if (t != NULL && t->roll == roll) {
		head = t->right;
		delete t;

		cout << "Record Deleted "<< "Successfully\n";
		return 0;
	}

	// traverse through the list
	while (t != NULL && t->roll != roll) {
		p = t;
		t = t->right;
	}
	// record not found
	if (t == NULL)
    {
		cout << "Record does not Exist\n";
		return -1;
    }
	// delete at middle
    if(t->right!=NULL)
	{
        p->right = t->right;
        t->right->left=p;
    }
	// delete at end
    else
    {
        p->right=NULL;
    }

		delete t;
		cout << "Record Deleted "<< "Successfully\n";

		return 0;

}

// function to show all records
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "<< "Available\n";
	}
	else {
		cout << "Index\tName\tCourse"<< "\tMarks\n";

		//
		while (p != NULL) {
			cout << p->roll << " \t"
				<< p->Name << "\t"
				<< p->Dept << "\t"
				<< p->Marks << endl;
			p = p->right;
		}
	}
}

// function to navigate through the list
void navigation()
{
    Node* p=head;
	while(true)
	{
		Search_Record(p->roll);
		label:
		cout<<"Press 'n' for next and 'p' for previous record\n";
		cout<<"Press e to exit to menu\n";
		char ch;
		cin>>ch;
		cout<<endl;

		if(ch=='n' && (p->right)!=NULL)
		{
			p=p->right;
		}
		else if(ch=='n' && (p->right)==NULL)
		{
			cout<<"Reached the end\n";
			goto label;
		}
		else if(ch=='p' && (p->left)!=NULL)
		{
			p=p->left;
		}
		else if(ch=='e')
		break;
		else
		{
			cout<<"Reached the start\n";
			goto label;
	}
}
}

//main function
int main()
{
	head = NULL;
	string Name, Course;
	int Roll, Marks;

	// main menu
	while (true) {
		cout << "\n\t\tWelcome to Student Record Management System\n\n\t1. Create a new Record\n\t2. Delete a student record\n\t3. Search a Student "
				"Record\n\t4. View all students record\n\t5. Navigate through records\n\t 6. Exit\n";
		cout << "\nEnter your Choice\n";
		int Choice;

		cin >> Choice;
		if (Choice == 1) {
			cout << "Enter Name of Student\n";
			cin >> Name;
			cout << "Enter Roll Number of Student\n";
			cin >> Roll;
			cout << "Enter Course of Student \n";
			cin >> Course;
			cout << "Enter Total Marks of Student\n";
			cin >> Marks;
			Insert_Record(Roll, Name, Course, Marks);
		}
		else if (Choice == 2) {
			cout << "Enter Roll Number of Student whose record is to be deleted\n";
			cin >> Roll;
			Delete_Record(Roll);
		}
		else if (Choice == 3) {
			cout << "Enter Roll Number of Student whose record you want to Search\n";
			cin >> Roll;
			Search_Record(Roll);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			navigation();
		}
		else if(Choice == 6){
			exit(0);
		}
		else {
			cout << "Invalid Choice "<< "Try Again\n";
		}
	}
	return 0;
}

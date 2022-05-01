#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Student{
public:
Student *next;
int marks;
string name;
Student (int m = 0,  string s= NULL, Student *n = NULL ){
	name = s;
	marks = m;
	next = n;
}
int getMarks(){
	return marks;
}
void setMarks(int m){
	marks= m;
}

string getName(){
	return name;
}
void setName(string n){
	name= n;
}

Student* getNextStudent(){
	Student *s = this->next;
	string name = s->name;
	int marks = s->marks;
	Student *nextStudent =  new Student(marks, name);
	return nextStudent;
}
void setNextStudent(Student s){
	name = s.name;
	marks = s.marks;
}
};

template <class N, class M>
class Stack{ 
	Student *head;
public:
Stack(){ head = new Student(); head -> next = head; }

	bool isEmpty(){	
	if(head->next == head) return true;	
	else return false ;}
	
	void push(N name, M marks){
		Student *newStudent = new Student(marks,name, head->next);
		head->next =  newStudent;
	}
	void pop(){
		if (isEmpty())	throw(0);
		Student *s = head->next;
		head->next = s->next;
		cout<<"Name: " << s->getName() <<" Marks: " << s->getMarks();
	}
	Student* seeTop(){
		if (isEmpty())	throw(0);	
		return head->getNextStudent();
	}
	void display(){	
		Student *s = head->next;
		while(s != head) {
			cout<<"Name: " << s->getName() <<" Marks: " << s->getMarks() <<'\n';	
			s =  s->next;
		}
	}
	Student* topMarksStudent(){
		Student *s = head->next;
		int heighest_marks = head->marks;
		Student *newstudent = head;
		while(s != head) {
			if(heighest_marks < s->marks){
				heighest_marks = s->marks;
				newstudent = s;	
			}
			s =  s->next;
		}
	return newstudent;
	}

};

int main(){
	Stack <string, int> stack;
	string name;
	int marks;
	Stack <string, int> sec_stack;
	int choice;	
	while(true){
		cout <<"---MENU---\n";
		cout <<"1-ADD STUDENT\n";
		cout <<"2-REMOVE STUDENT\n";
		cout <<"3-DISPLAY STUDENT\n";
		cout <<"4-TOP THREE STUDENT\n";
		cout <<"5-EXIT\n";
		cin>>choice;
		switch (choice)
		{
		case 1:	
			cout << "Name: ";
			cin >> name;
			cout << "Marks";
			cin >> marks;
			stack.push(name, marks);
			break;
		case 2:	
			stack.pop();
			break;
		case 3:		
			stack.display();
			break;
		case 4:
			name = stack.topMarksStudent()->name;
			marks = stack.topMarksStudent()->marks;
			sec_stack.push(name, marks);
			sec_stack.display();
			break;
		case 5:
			return 0;
			break;	
		}
	}
	return 0;
}
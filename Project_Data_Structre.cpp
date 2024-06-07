#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class employee{
	struct node{
		string name;
		int id;
		int salary;
		string date;
		int phone_number;
		node*next;
	};
	node*first;
	node*last;
	int length;
	public:
		employee(){
			first=last=	NULL;
			length=0;
		} 
		void add_employee(string name , int id , int salary , string date , int phone_number){
			node*newnode=new node;
			newnode->name=name;
			newnode->id=id;
			newnode->salary=salary;
			newnode->date=date;
			newnode->phone_number=phone_number;
		if(length==0){
			first=last=newnode;
			newnode->next=NULL;
		}
		else{
			last->next=newnode;
			newnode->next=NULL;
			last=newnode;
		}
		length++;
		    cout << "Employee added successfully!" << endl;
		}
	
		
		bool is_empty(){
			return length==0;
		}
		
	
		
    
    void sort_by_id() {
  if (is_empty()) {
    cout << "List is empty. Sorting cannot be performed." << endl<< endl << endl;
    return;
  }

  node* curr = first;
  node* min = curr;

  while (curr != NULL) {
    node* next = curr->next;
    while (next != NULL) {
      if (next->id < min->id) {
        min = next;
      }
      next = next->next;
    }

  
    swap(curr->id, min->id);
    swap(curr->name, min->name);
    swap(curr->salary, min->salary);
    swap(curr->date, min->date);
    swap(curr->phone_number, min->phone_number);

    curr = curr->next;
    min = curr;
  }

  cout << "Employee list sorted by ID successfully!" << endl<< endl<< endl;
}
						
	
			
		void remove_employee(int id){
			if(is_empty()){
				cout<<"Empty List.......! Cant Remove any Element";
				return;
			}
			node *curr , *prev;
			if(first->id==id){
				curr=first;
				first=first->next;
				curr->next=NULL;
				delete curr;
				length--;
				if(length==0)
				last = NULL;
			}
			else{
				curr = first->next;
				prev = first;
				while (curr !=NULL){
					if(curr->id == id)
					break;
					prev = curr;
					curr = curr->next;
				}
				if(curr == NULL)
				cout<<"The Element Not Found";
				else
				{
					prev->next = curr->next;
					if(last ==curr)
					last = prev;
					delete curr;
					length--;
				}
			}	
		}
		
		
		
     void print(){
     	node*cur = first;
     	if(is_empty())
     	cout<<" \n No employees found............\n\n\n";
     	else{
     	while (cur!=NULL){
     	 	cout<<" * Name = "<<cur->name<<"  * ID = "<<cur->id<<" * SALARY = "<<cur->salary<<"  * DATE = "<<cur->date<<"  * Phone_Number = "<<cur->phone_number<<endl;
     		cur=cur->next;
     		
		 }
		 }
	 }
		
		
		
    void searchEmployee_ID(int id){
        node *temp = first;
         while (temp != NULL) {
            if (temp->id == id) {
                cout << "Employee details:" << endl;
                 cout << " Name : " << temp->name  << "  ID : " << temp->id << "  Salary : " << temp->salary << "  Joining Date : " << temp->date <<"  Phone_Number : "<<temp->phone_number<< endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found!" << endl;
    }
    
    
	
    void updateEmployee(int id) {
        node*temp = first;
        int f;
        cout<<"To Update Name choose 1 \n";
        cout<<"To Update ID choose 2 \n";
        cout<<"To Update Salary choose 3 \n";
        cout<<"To Update Date choose 4 \n";
        cout<<"To Update Phone_Number choose 5 \n";
        cout<<"enter your choise: ";
        cin>>f;
        cout<<endl;
        switch(f){
        	case 1:
        		 while (temp != NULL) {
			            if (temp->id == id) {
			            	string h;
			            	cout<<"Enter New Name : ";
			            	cin>>h;
			                temp->name = h;
			                cout << "Employee details updated successfully!" << endl;
			                return;
			            }
			           		 temp = temp->next;
			      	    }
			      	    break;
        		
        	case 2:
        		 while (temp != NULL) {
			            if (temp->id == id) {
			            	int h;
			            	cout<<"Enter New ID : ";
			            	cin>>h;
			                temp->id = h;
			                cout << "Employee details updated successfully!" << endl;
			                return;
			            }
			           		 temp = temp->next;
			      	    }
			      	    break;
        	case 3:
        		 while (temp != NULL) {
			            if (temp->id == id) {
			            	int h;
			            	cout<<"Enter New Salary : ";
			            	cin>>h;
			                temp->salary = h;
			                cout << "Employee details updated successfully!" << endl;
			                return;
			            }
			           		 temp = temp->next;
			      	    }
        				break;
        	case 4:
        		 while (temp != NULL) {
			            if (temp->id == id) {
			            	string h;
			            	cout<<"Enter New Date : ";
			            	cin>>h;
			                temp->date = h;
			                cout << "Employee details updated successfully!" << endl;
			                return;
			            }
			           		 temp = temp->next;
			      	    }
        				break;
        	case 5:
        		 while (temp != NULL) {
			            if (temp->id == id) {
			            	int h;
			            	cout<<"Enter New phone_number : ";
			            	cin>>h;
			                temp->phone_number = h;
			                cout << "Employee details updated successfully!" << endl;
			                return;
			            }
			           		 temp = temp->next;
			      	    }
			      	    break;
        		
        	default:
			cout << "Employee not found!" << endl;
		}

    }
		
	    void search_period(){
        node*temp = first;
        int f , start , end , count=0;
        cout<<"\n\n1. To Search By Use ID  \n";
        cout<<"2. To Search By Use Salary \n";
        cout<<"3. To Search By Use Phone_Number \n";
        cout<<"enter your choise: ";
        cin>>f;
        cout<<endl;
        cout<<"Enter first Number you want to start search from it:";
        cin>>start;
        cout<<endl;
        cout<<"Enter Last Number you want to End search by it:";
        cin>>end;
        cout<<endl;
        if(end>=start){
        switch(f){        		
        	case 1:
        		 while (temp != NULL) {
			            if (temp->id>=start && temp->id<=end) {			            
					    cout << "Employee details "<<count+1<<":"<< endl;
		                cout << " Name : " << temp->name  << "  ID : " << temp->id << "  Salary : " << temp->salary << "  Joining Date : " << temp->date <<"  Phone_Number : "<<temp->phone_number<< endl;
              	        count++;
			            }
			            temp = temp->next;
			      	    }
			      	    if(count==0)
			      	    cout<<"Employee details Not Found \n\n";
			      	    break;
        	case 2:
        		 while (temp != NULL) {
			            if (temp->salary>=start && temp->salary<=end) {			            
					     cout << "Employee details "<<count+1<<":"<< endl;
		                cout << " Name : " << temp->name  << "  ID : " << temp->id << "  Salary : " << temp->salary << "  Joining Date : " << temp->date <<"  Phone_Number : "<<temp->phone_number<< endl;
              	        count++;
			            }
			            temp = temp->next;
			      	    }
			      	    cout<<"Employee details Not Found \n\n";
			      	    break;
        		
        	case 3:
        		 while (temp != NULL) {
			            if (temp->phone_number>=start && temp->phone_number<=end) {			            
					     cout << "Employee details "<<count+1<<":"<< endl;
		                cout << " Name : " << temp->name  << "  ID : " << temp->id << "  Salary : " << temp->salary << "  Joining Date : " << temp->date <<"  Phone_Number : "<<temp->phone_number<< endl;
              	        count++;
			            }
			            temp = temp->next;
			      	    }
			      	    cout<<"Employee details Not Found \n\n";
			      	    break;
        		
        	default:
			cout << "Employee Case not found....Please Try Again!" << endl;
		}
		cout<<"\n Count Number Of Result = "<<count<<endl;
		cout<<endl<<endl<<endl;
		}
		else
		cout<<"The Data You Entered Is Incorrect ...Please Try again \t*note(Start <= End) \n\n";
		
    }
    		
};

int main() {
 employee n;
    int choice, fun ,sec;
 		string name;
		int id;
		int salary;
		string date;
		int phone_number;

  while (true) {
    cout << "\nEmployee Database Management System ......." << endl;
    cout << "1. Administrator Mode" << endl;
    cout << "2. Guest Mode" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
       
        cout << "\nAdministrator Mode" << endl;
        while (true) {
          cout << "1/ Add Employee" << endl;
          cout << "2/ Remove_Employee " << endl;
          cout << "3/ Print" << endl;
          cout << "4/ SearchEmployee_ID" << endl;
          cout << "5/ UpdateEmployee" << endl;
          cout << "6/ Search_By_Period" << endl;
          cout << "7/ Sort By Id " <<endl;
          cout << "0/ Go back" << endl;
          cout << "Enter your choice: ";
          cin >> fun;
          if (fun == 0) {
            break;
          }
         else if (fun == 1) {
          	cout<<"Enter Your Name...";
          	cin>>name;
          	cout<<endl;
          	cout<<"Enter Your ID...";
          	cin>>id;
          	cout<<endl;
          	cout<<"Enter Your Salary...";
          	cin>>salary;
          	cout<<endl;
          	cout<<"Enter Your Date...";
          	cin>>date;
          	cout<<endl;
          	cout<<"Enter Your Phone_Number...";
          	cin>>phone_number;
          	cout<<endl;
            n.add_employee( name ,id , salary , date , phone_number);
          }
          else if (fun == 2) {
            int g;
            cout<<"Enter Employee ID....";
            cin>>g;
            cout<<endl;
            if(g<0)
          	cout<<"ERROR......Please Try Again \n";
          	else
            n.remove_employee(g);
          }
         else if (fun == 3) {
            n.print();
          }
          else if (fun == 4) {
          	int f;
          	cout<<"Enter Employee ID....";
          	cin>>f;
          	cout<<endl;
          	if(f<0)
          	cout<<"ERROR......Please Try Again \n";
          	else
            n.searchEmployee_ID(f);
            
          }
          else if (fun == 5) {
          	int d;
          	cout<<"Enter ID Element You Want To Update....";
          	cin>>d;
          	cout<<endl;
          	if(d<0)
          	cout<<"ERROR......Please Try Again \n";
          	else
            n.updateEmployee(d);
          }
         else if (fun == 6) {
            n.search_period();
          }
         else if (fun == 7){
         	n.sort_by_id();
		 }
        }
        break;
        
      case 2: 
        cout << "\nGuest Mode" << endl;
       	cout << "0. Go back"   << endl;
       	cout << "1. SearchEmployee_ID" << endl;
       	cout << "Enter your choice: ";
       	cin  >> sec;
       	    if (sec== 0) {
            break;
	   	   }
	       else if (sec== 1) {
          	int f;
          	cout<<"Enter Employee ID....";
          	cin>>f;
          	cout<<endl;
          	if(f<0)
          	cout<<"ERROR......Please Try Again \n";
          	else
            n.searchEmployee_ID(f);
           
		   }
		    
       break;
       case 3:
       	return 0;
       	
       	default:
       		cout<<"ERROR Data....Please Try Again \n";
     }}



}

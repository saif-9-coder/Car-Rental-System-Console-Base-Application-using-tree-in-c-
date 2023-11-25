#include<iostream>
using namespace std;
struct node
{
	string status;
	int car_number;
	string car_name;
	int rent;
	string car_model;
	string car_color;
	int car_price;
	struct node * left;
	struct node * right;
};
class admin
{
	public:
	struct node * root=NULL;
//    global 
	
	int rent_price(node * root,int n,int m)
	{  int y;
		if(n==root->car_number)
		{
			y=m*root->rent;
			return y;
		}
			rent_price(root->left,n,m);
	        rent_price(root->right,n,m);
	}
	void rent_car()
	{
		int n,m,y;
    	cout<<"\t\t:Car Number:   :Car Name:   :Car Model:   :Car Price:    :Car color:   :Rent(pkr):        :Status:"<<endl;		
		car_list(root);
		cout<<"Which car you want to on rent Enter Car Nmber=";
		cin>>n;
//		search_car(root,n);
		cout<<"Enter Days for Rent A Car=";
		cin>>m;
		y=rent_price(root,n,m);
		cout<<"\t\tTotal rent of "<<m<<" "<<"days"<<"="<<" ( "<<y<<" ) "<<endl;
		modify_status(root,n);
	}
void modify_status(node * root,int x)
 { 
    if(x==root->car_number)
    {
    	string status="On Rent";
    	root->status=status;
    	return;
	}
		search_car(root->left,x);
		search_car(root->right,x);
 }
void modify_car(node * root,int x)
 { 
    if(x==root->car_number)
    {
    	int new_rent;
    	cout<<"Enter New Rent = ";
    	cin>>new_rent;
    	root->rent=new_rent;
    	cout<<"\t\tYES...Rent details have updated"<<endl;
    	return;
	}
		search_car(root->left,x);
		search_car(root->right,x);
 }		
void search_car(node * root,int x)
{
	if(x==root->car_number)
	{
		cout<<"Yes This Car Exist >>>>>"<<endl;
    	cout<<"\t\t:Car Number:   :Car Name:   :Car Model:   :Car Price:    :Car color:   :Rent(pkr):        :Status:"<<endl;
        cout<<"\t\t "<<root->car_number<<"            "<<root->car_name<<"         "<<root->car_model<<"         "<<root->car_price<<"          "<<root->car_color<<"         "<<root->rent<<" (per day)"<<"      "<<root->status<<endl;
	car_list(root->right);
		return;
	}
	search_car(root->left,x);
	search_car(root->right,x);
	cout<<"\tSORRY >>> This Number Of Car Not Exist>>>>"<<endl;
}
void car_list(struct node * root)
{
	if(root==NULL)
	{
		return;
	}
	car_list(root->left);
	cout<<"\t\t "<<root->car_number<<"            "<<root->car_name<<"         "<<root->car_model<<"         "<<root->car_price<<"          "<<root->car_color<<"         "<<root->rent<<" (per day)"<<"      "<<root->status<<endl;
	car_list(root->right);
}
node * newnode(int x)
{   
    string status;
    string car_name;
    string car_color;
    string car_model;
    int car_price;
    int rent;
	struct node * temp = new node ();
	temp->car_number=x;
	cout<<"Enter Car Name = ";
	cin>>car_name;
	temp->car_name=car_name;
		cout<<"Enter Car Model = ";
	cin>>car_model;
	temp->car_model=car_model;
		cout<<"Enter Car Price = ";
	cin>>car_price;
	temp->car_price=car_price;
		cout<<"Enter Car color = ";
	cin>>car_color;
	temp->car_color=car_color;
		cout<<"Enter Car Rent (per day)= ";
	cin>>rent;
	temp->rent=rent;
    status="On Stand";
    temp->status=status;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node * insert (struct node * root,int x)
{
	if(root==NULL)
	{
		return newnode(x);
	}
	if (x< root->car_number)
	{
        root->left = insert(root->left,x);
    }
    else
    {
	
        root->right = insert(root->right,x);        
    }
    return root;
}
struct node * minvalue(node * p)
{
	struct node * temp =p;
	while(temp && temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
struct node * remove_car(node * root,int x)
{
	if(root==NULL)
	{
		return root;
	}
	if (x<root->car_number)
	{
		root->left=remove_car(root->left,x);
	}
	else if (x>root->car_number)
	{
		root->right=remove_car(root->right,x);
	}
	else
	{
		if(root->left==NULL && root->right==NULL )
		{
			return NULL;
		}
		else if (root->left==NULL)
		{
			struct node * temp = root->right;
			delete(root->right);
			return temp;
		}
		else if (root->right==NULL)
		{
			struct node * temp = root->left;
			delete(root->left);
			return temp;
		}
		else
		{
//			successer
			struct node * temp = minvalue(root->right);
			root->car_number=temp->car_number;
			root->right=remove_car(root->right,temp->car_number);
		}
	}
	return root;
}
void customer()
    {
    	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << Customer MENU >>   )....>>>>>>>>"<<endl;
	cout<<endl<<"ENTER (1) >>>>>> Watch Car List"<<endl;
	cout<<"ENTER (2) >>>>>> Rent A New Car "<<endl;
	cout<<"ENTER (3) >>>>>> Again in Customer Menu "<<endl;
	cout<<"ENTER (4) >>>>>> Exit to Main Menu "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
	{
		case 1:
	      	cout<<"\t\t:Car Number:   :Car Name:   :Car Model:   :Car Price:    :Car color:   :Rent(pkr):        :Status:"<<endl;
			car_list(root);
			customer();
    	break;
    	case 2:
    		rent_car();
    		customer();
    		break;
    		case 3:
    			customer();
    			break;
    		case 4:
    			main_menu();
    			break;
	}
}
void admin_menu()
{
//	struct node* root = NULL;
	int y,x,n,m;
	int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << ADMIN MENU >>   )....>>>>>>>>"<<endl;
	cout<<endl<<"ENTER (1) >>>>>> Add New Car "<<endl;
	cout<<"ENTER (2) >>>>>> Watch Car List "<<endl;
	cout<<"ENTER (3) >>>>>> Rent A Car "<<endl;
	cout<<"ENTER (4) >>>>>> Search A Car "<<endl;
	cout<<"ENTER (5) >>>>>> Remove A Car "<<endl;
	cout<<"ENTER (6) >>>>>> Modify Car Rent "<<endl;
	cout<<"ENTER (7) >>>>>> Back To Admin Menu "<<endl;
	cout<<"ENTER (8) >>>>>> Exit To Main menu"<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch){
	case 1:
		cout<<"Enter Car Number=";
	    cin>>x;
        root = insert(root,x);
		admin_menu();
		break;
    case 2:
    	cout<<"List Of All Cars >>>>>"<<endl<<endl;
    	cout<<"\t\t:Car Number:   :Car Name:   :Car Model:   :Car Price:    :Car color:   :Rent(pkr):        :Status:"<<endl;
    	car_list(root);
    	admin_menu();
    	break;
    case 3:
	     rent_car();
		 admin_menu();
		 break;	
	case 4:
		   cout<<"Enter Car Name which you want to search=";
		   cin>>n;
	       search_car(root,n);
		   admin_menu();
		   break;
	case 5:
		cout<<endl<<"Enter number of car which you want remove=";
        cin>>y;
        root=remove_car(root,y);
        admin_menu();
	    break;	 
	case 6 :
		 cout<<"Enter Car Number Which You Want to update=";
		 cin>>m;
	      modify_car(root,m);
		  admin_menu();
		  break;	  	 
    case 7:
        admin_menu();
    	break;
    case 8:
    	main_menu();
    	break;
   
	}
}
void main_menu()
{   
    int ch;
	cout<<endl<<"\t\t<<<<<<<....(  << MAIN MENU >>   )....>>>>>>>>"<<endl;
	cout<<"ENTER (1) >>>>>> Admin Menu "<<endl;
	cout<<"ENTER (2) >>>>>> Customer Menu "<<endl;
	cout<<"ENTER (3) >>>>>> Exit "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch)
    {
    	case 1:
    		admin_menu();
    	break;
		case 2:
		    customer();
			break;
			case 3:
				cout<<"\t\t\tTHANK YOU .....>>>>";
				break;
				
	}
}
};
main()
{   admin a;
    cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|     ****    RENT A CAR PORTAL   ****     |"<<endl;
	cout<<"\t\t============================================"<<endl;
	a.main_menu();
}


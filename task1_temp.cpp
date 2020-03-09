#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<string> master_list;
	
	
	list<string> terminal;
	
		terminal.push_back("idList");
		terminal.push_back("colon");
		terminal.push_back("ID");
		terminal.push_back("ID");
		terminal.push_back("idList1");
		terminal.push_back("COMMA");
		terminal.push_back("ID");
		terminal.push_back("idList1");
		

	list<string>::iterator it_T;

	cout<<"Terminal:-"<<endl;
	for(it_T = terminal.begin(); it_T != terminal.end(); it_T++)
	{
		cout<<*it_T<<"\t";
		master_list.push_back(*it_T);
	}

		cout<<endl;
		cout<<endl;
	
	list<string> non_terminal;
		non_terminal.push_back("decl");
		non_terminal.push_back("idList");
		non_terminal.push_back("idList1");
		non_terminal.push_back("idList1");
		
		
	list<string>::iterator it_NT;
	cout<<"Non Terminal:-"<<endl;
	for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
	{
		cout<<*it_NT<<"\t";
		master_list.push_back(*it_NT);
	}

	
	cout<<endl;
	cout<<endl;
	
	
	list<string>::iterator it_ML;
	cout<<"Master List:-"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Creation of Main List starts"<<endl;
	
	list<string> main_list;
	
	string temp;
	for(it_T = terminal.begin(); it_T != terminal.end(); it_T++)
	{
		for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
		{
			if(*it_T == *it_ML)
			{	
				cout<<*it_T<<endl;
				temp = *it_T;
				main_list.push_back(temp);
				break;
				
			}
			
		}
	master_list.remove(temp);
	}
	cout<<"Master List after removing Terminals"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
	{
		for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
		{
			if(*it_NT == *it_ML)
			{	
				cout<<*it_NT<<endl;
				temp = *it_NT;
				main_list.push_back(temp);
				break;
			}
		
		}
	master_list.remove(temp);	
	}
	cout<<endl;
	cout<<"Master List after removing Non Terminals"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Main List :-"<<endl;
	list<string>::iterator it_MaL;
	for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		cout<<*it_MaL<<endl;
	}

	
	
}



//This file is responsibnle for task1  = listing down terminal & non-terminal 

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define GRAMMAR_RULE 4

int main()
{

	string str[GRAMMAR_RULE] = {"decl -> idList colon ID #",
			 "idList -> ID idList1 #",
			 "idList1 -> #",	
			 "idList1 -> COMMA ID idList1 #"};

	cout<<"Input grammar:"<<endl;
	for(int i = 0 ; i < GRAMMAR_RULE ; i++)
	{
		cout<<str[i]<<endl;
	}
	cout<<"Grammar breakup:"<<endl;
	list<string> non_terminal;	
	list<string> terminal;
	for(int i = 0 ; i < GRAMMAR_RULE ; i++)
	{
		size_t pos = str[i].find("->");
		non_terminal.push_back(str[i].substr(0,pos));
		cout<<"RHS = "<<str[i].substr(0,pos)<<"\t";
		string strX = str[i].substr(pos);
		string strY = strX.erase(0,3);
		
		cout<<"LHS = ";

		string s = strY;
		string delimiter = " ";

		size_t posX = 0;
		string token;
		while ((posX = s.find(delimiter)) != string::npos) {
		    token = s.substr(0, posX);
		    cout << token << "\t";
			terminal.push_back(token);
		    s.erase(0, posX + delimiter.length());
			}
		std::cout << s << std::endl;
	}
	cout<<endl;
	cout<<"non-terminals size"<<non_terminal.size()<<endl;
	cout<<"non-terminals"<<endl;

	list<string> my_non_terminal(non_terminal);
	list<string> my_terminal(terminal);
	
	while(!non_terminal.empty())
	{
		cout<<non_terminal.front()<<endl;
	//	my_non_terminal = non_terminal.front();		
		non_terminal.pop_front();
	}
	cout<<endl;
	cout<<"terminals size"<<terminal.size()<<endl;
	cout<<"terminals"<<endl;

	while(!terminal.empty())
	{
		cout<<"--"<<terminal.front()<<endl;
//		my_terminal = terminal.front();
		terminal.pop_front();
	}

	cout<<"my non terminals size"<<my_non_terminal.size()<<endl;
	cout<<"my terminals size"<<my_terminal.size()<<endl;
	
	my_terminal.sort();
	my_terminal.unique();
	my_non_terminal.unique();

	list<string>::iterator it;
	for(it = my_terminal.begin();it !=my_terminal.end(); it++)
	{	
		cout<<*it<<"\t";	

	}
	cout<<endl;
}

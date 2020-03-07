//This file is responsibnle for task1  = listing down terminal & non-terminal 

#include <iostream>
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
	for(int i = 0 ; i < GRAMMAR_RULE ; i++)
	{
		size_t pos = str[i].find("->");
		cout<<"RHS = "<<str[i].substr(0,pos)<<"\t";
		string strX = str[i].substr(pos);
		string strY = strX.erase(0,2);
		
		cout<<"LHS = ";

		string s = strY;
		string delimiter = " ";

		size_t posX = 0;
		string token;
		while ((posX = s.find(delimiter)) != string::npos) {
		    token = s.substr(0, posX);
		    cout << token << "\t";
		    s.erase(0, posX + delimiter.length());
			}
		std::cout << s << std::endl;
	}
}

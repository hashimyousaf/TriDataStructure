#include<iostream>
#include <predictot.h>
#include <list>
#include <windows.h>
using namespace std;
	
	int trie :: char_to_int(char c){
		
		if(c =='a' || c =='b' || c =='c' )
			return 2;
		
		if(c =='d' || c =='e' || c =='f' )
			return 3;
		
		if(c =='g' || c =='h' || c =='i' )
			return 4;
			
		if(c =='j' || c =='k' || c =='l' )
			return 5;
				
		if(c =='m' || c =='n' || c =='o' )
			return 6;
			
		if(c =='p' || c =='q' || c =='r' || c=='s' )
		
			return 7;
			
		if(c =='t' || c =='u' || c =='v' )
			return 8;	
			
		if(c =='w' || c =='x' || c =='y' || c =='z' )
			return 9;	
				
	}
	
	trie :: trie(){													// CONSTRUCTOR 
		
		node *newnode = new node;
		root = newnode;
		for(int i=0; i<8;i++)
			root->children[i]= NULL;
//		root->words=NULL;	
		root->data=100;	
	}
	
void trie :: insert(){										// insert function 
	std::ifstream file("dictionary.txt");
	if(file.is_open())
	 {
	    char ch[40];
	    
	    int temp;
		int j;
		
		node *t ;
		node *newnode ;
		char *ptr ;
		while (file.getline(ch , 40))
	    {
	    	ptr = new char[strlen(ch) + 1];
	    	strcpy( ptr , ch ) ;
	
	       t = root;
	    	for(int i=0;i<strlen(ch);i++)
			{
				
				temp = this->char_to_int(ch[i]);
				j= temp-2;        // 0
//				 cout << "temp   " << temp << endl;
				 //cin.get();
				
				
				if(t->children[j]!=NULL)
				{ 
	//				s=t;
					t=t->children[j];
	//				cout << "in IF   placing "<< temp << "  at  " << j << "  position "<< endl ; 
					//cin.get();
				}	
				else
				{
					newnode = new node();	             // creating newnode 
					newnode->data = temp;				// setting data in it 
	//				cout << "else    placing "<< temp << "  at  " << j << "  position "<< endl ; 
						//cin.get();
					t->children[j]= newnode;
					t = newnode;	
				}
			}
			
			t->words.push_back( ptr );                         // here we will add words in linklist push_back add at the end of lit  
		}
	}
	else 
	cout << "Error in file opening \n";
}		




void trie :: dictionary()
{
    char ch[30];
    //	cin.get();
    cout << "\n\n entere number in T9 text predictor  ";
    cin>>ch;
	int node_to_move ;
	node  *t = root ;
	
//	cout << "here ";

	for(int i= 0 ; i < strlen(ch) ; i++)
	{
		if(ch[i] >= 50 && ch[i] <= 57)
		{
			node_to_move =  ch[i]  - 50;
			
			if(t->children[node_to_move]!=NULL)
				{ 
//				cout << "if";
					t = t->children[node_to_move] ;
//					cout << t->data;
				}	
				else
				{
					cout << "\nNo word in dictionary with such a combination  \n\n";
					return ;	
				}
		}
		else 
		{
				cout << "\nyou have entered  invalid identity \n";      //you can add check here to deal with 1 further 
				return ;
		}
	}

	list<char *>::iterator pos ;     // declaring iterator to traverse in linlist 
	
	            

	
	char check , *ptr ;
	if(!t->words.empty())
	{
		pos = t->words.begin(); 					// assigning iterator to very first postion in linklist
		cout << "\nlist of words in this path \n";
		
		do
		{
			showstr(*pos);
			pos++;
			cout << "Enter '#' for next words else other    :"  ; check = getche()  ; cout << endl  ;
			if(check!= '#')
			return ;
			
			
		}while(pos!= t->words.end());
		
		cout << "words ended for this combination   \n ";
	}
	else 
	cout << "\n there is no word in dictionary with this combination   \n";
//	do{
//		ptr = *pos;
//			
//		showstr( ptr );            // here is problem with 953 if we enter 
//			cout << "here ";
//	cin.get();
//		pos++;
//		
//		cout <<" ENTER '#'  for next Else any charater    :";
//		cin>> check ;
//		
//	}while(check=='#');	
}


void trie :: level_order()         		// level_order  display 
{
	node *temp=root;
	queue <node *> tq;	 
	 tq.push(temp);
	 while(!tq.empty())
	 {
	 	temp = tq.front();
	 	cout << temp->data<<"  ";
	 	cin.get();
	 	int i=0 ;
	 	while(i<8)
	 	{
		 	
		 	if(temp->children[i]!= NULL)
		 	{
			 	tq.push(temp->children[i]);
			 	
		 	}
		 	i++;
	 	}
	 	tq.pop();
	 }
	
}

void trie ::  showstr(char *ptr)
{
	while(*ptr)
	{
		cout <<*ptr;
		ptr++;

	}
	cout << endl;

}	

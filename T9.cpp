#include<iostream>
#include <fstream>
#include <string.h>
#include "predictot.h"
#include "class1.h"
//#include <list>
//#include <queue>
//#include <windows.h>
//#include <conio.h>
using namespace std;


int main() 
{ 
    
    
    trie t;
    t.insert();
    char check[10];
    do{
    		t.dictionary();
    		
    		cout << "\nEnter 'EXIT' to exit and other to continue   : ";
    		
			cin>>check ;
			
	}while(strcmp(check , "EXIT") != 0);
    
    

    
    
//     list<char *>::iterator pos ;
//     pos =  t.root->children[0]->children[0]->words.begin();
//     char *ptr = *pos ;
//     
//    while(*ptr)
//    {
//    	cout << *ptr ;
//    	ptr++;
//    }
//	cout <<endl << t.root->children[0]->children[0]->data << endl ; //2
//    
//    cout << t.root->children[0]->children[5]->data << endl ; //6
    
    
	cout << "\n\nMain terminated "<< endl ;
	
	
    
   //t.level_order();
    return 0;
    
}

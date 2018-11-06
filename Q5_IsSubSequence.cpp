/*
	Some of your friends have gotten into the burgeoning field of time-series data
mining, in which one looks for patterns in sequences of events that occur over time.
Purchases at stock exchanges --- what's being bought --- are one source of data with a

natural ordering in time. Given a long sequence S of such events, your friends want an
efficient way to detect certain "patterns" in them --- e.g. they may want to know if the
four events
buy Yahoo, buy eBay, buy Yahoo, buy Oracle
occur in this sequence S, in order but not necessarily consecutively. They begin with a
finite collection of possible events (e.g. the possible transactions) and a sequence S of
n of these events. A given event may occur multiple times in S (e.g. Yahoo stock may
be bought many times in a single sequence S). We will say that a sequence S' is a
subsequence of S if there is a way to delete certain of the events from S so that the
remaining events, in order, are equal to the sequence S'. So for example, the sequence
of four events above is a sub-sequence of the sequence

buy Amazon, buy Yahoo, buy eBay, buy Yahoo, buy Yahoo, buy Oracle

Their goal is to be able to dream up short sequences and quickly detect whether they
are subsequences of S. So this is the problem they pose to you: Give an algorithm that
takes two sequences of events --- S' of length m and S of length n, each possibly
containing an event more than once --- and decides in time O (m + n) whether S' is a
subsequence of S.
*/


#include <iostream>
#include<string>

using namespace std;
bool isSubSeq ( string SPrime ,string S)
{
   int j = 0;
   int i;
    for (  i=0;i< S.length() ; ++i )
    {
    	//if all letters of string SPrime is traversed 
        if ( j == SPrime.length() )
            break;
        if ( SPrime [ j ] == S [ i ])
            ++j;
        
    }
    
    if( j == SPrime.length() && j!=0)
    {   
        return true ;
    }
    return false;
    
}
    
int main()
{
	string str1,str2; 
      
    cout << "Please enter subsequence S': \n"; 
    getline (cin, str1); 
    
    cout << "Please enter sequence S: \n"; 
    getline (cin, str); 
    
    bool value=isSubSeq(str1, str2);
    if(value==true)
    {
    	cout<<"SPrime is a subsequence of S";
    	
	}
	else
	{
		cout<<"SPrime is not a subsequence of S";
	}
    return 0; 

}


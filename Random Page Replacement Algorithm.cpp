#include <iostream>
#include <vector> 
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
using namespace std; 

void print(vector<int>); //this function was to check each input to make sure my implementation was right

void print(vector<int> cache)
{
	for(int i = 0; i < cache.size(); i++)
	{
		cout << cache[i] << "  "; 
	}
	cout << endl; 
}

int main(int argc, char* argv[])
{
  	int SIZE = atoi(argv[1]);
	int i = 0; 
	int n = 0; 
	int num_faults = 0; 
	vector<int> cache(SIZE); 
	while(!cin.eof())
	{
		cin >> n; 
		bool in_cache = false; 
		for(int j = 0; j < cache.size(); j++)
		{
			if(cache[j] == n)
			{
				in_cache = true; //if n is already in the cache then set in_cache to true
				break; 
			}
		}
		if(in_cache != true) //if n is not in the cache then do this
		{
			num_faults++;   //keep track of page faults 
			if(i < cache.size()) //if the cache is not full and n is not already in cache put it in cache
                	{
                        	cache[i] = n;
				i++;
                	}
                	else
                	{
                        	int random = rand()%SIZE; //if cache is full then put it randomly somewhere in the cache
                        	cache[random] = n;	//rand()%SIZE returns a number between 0 and SIZE-1 
                	}
		} 
  	//	print(cache); 
		
	}
	cout << "The number of page faults is: " << num_faults << endl; 	
}

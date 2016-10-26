#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

void print(vector<int>, vector<int>); //Print function to check each entry while I was trying to implement second chance 

void print(vector<int> cache, vector<int> sc)
{
        for(int i = 0; i < cache.size(); i++)
        {
                cout << cache[i] << "  ";
        }
        cout << endl;
        for(int i = 0; i < cache.size(); i++)
        {
                cout << sc[i] << "  ";
        }
        cout << endl;
}

int main(int argc, char* argv[])
{
  	int SIZE = atoi(argv[1]);
	int num_faults = 0; 
	int i = 0; 
	int n = 0; 
	int clock = 0;
	vector<int> cache(SIZE);
        vector<int> sc(SIZE);
 
	while(!cin.eof())
	{
       		cin >> n;
		if(i < cache.size())
		{
			cache[clock] = n; //put the page into the cache and increment the clock
			clock++;
			num_faults++; 
		//	print(cache, sc);  
		}  
		else
		{
			bool in_cache  = false;
			bool replace = false; 
			for(int l = 0; l < cache.size(); l++)
			{
				if(cache[l] == n) 
				{
					sc[l] = 0; //if the page is already in the cache reset its second chance to 0
					in_cache = true; 
					break;  
				}
			}
			if(in_cache != true) //if the page is not in the cache then do this
			{
			
				while(replace != true)
                        	{
					clock = clock%SIZE; //makes sure the clock pointer is never greater than the size 
                                	if(sc[clock] == 0)
                                	{	
						sc[clock] = 1; //goes through and gives the pages a second chance
						clock++;
                               		} 
					else
					{
						replace = true; //if a page has already been given a second chance then replace it 
						break; 
					}
				}      
				if(replace == true)
				{
					sc[clock] = 0; 
					cache[clock] = n; //replacing the page 
					clock++; 	//increment the clock pointer 
					num_faults++; 
					cout << n << endl; 
				}
			} 
		//	print(cache,sc); 
		}
		i++; 
	}
	cout << "Number of Page Faults: " << num_faults << endl; 	
}

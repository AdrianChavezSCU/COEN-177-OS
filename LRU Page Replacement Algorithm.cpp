#include<iostream> 
#include <vector>
#include <stdlib.h> 
#include <algorithm> 
using namespace std;
 
void print(vector<int>, vector<int>); //I used this function to check indivudual entries into my LRU algorithm to 
					//make sure my LRU was running properly  

void print(vector<int> cache, vector<int> tracking)
{
        for(int i = 0; i < cache.size(); i++)
        {
                cout << cache[i] << "  ";
        }
        cout << endl;
        for(int i = 0; i < cache.size(); i++)
        {
                cout << tracking[i] << "  ";
        }
        cout << endl;
}
int main(int argc, char* argv[])
{
  	int SIZE = atoi(argv[1]);
	int i = 0; 
	int n = 0; 
	int num_faults = 0;  
	cout << "Please enter random numbers " << endl;  
	std::vector<int> cache(SIZE); //where the pages are stored 
	std::vector<int> tracking(SIZE); //keeps track of how long a page has been in the cache  
	while(!cin.eof())
	{
		cin >> n; 
		bool fault = false;  //boolean to check page faults 
		if(i < cache.size()) //checks to see if the cache is not already full
		{
			for(int k = 0; k < i; k++)  
                        {
                        	if(cache[k] != n) 
                                {
                                	tracking[k] += 1; //increment the time the pages in the cache that are not equal to n 
					fault = true;  //set page fault boolean to true 
				}
                                else
				{
					fault = false; 
                                        tracking[k] = 0; 
                                }
                        }
			//print(cache, tracking); 
			if(fault == true) //if a page fault occurred then cout it
                        {
				cache[i] = n; 
				num_faults++;  
                        	cout << n << endl; 
                        }
		}	
		else //when the cache is full then do this part of the code 
		{ 
			bool clone = false; 
			int max = 0; 
			int temp = 0; 	   
			for(int k = 0; k < cache.size(); k++)
                        {
                        	if(cache[k] != n) 
                               	{
                                	tracking[k] += 1; //increment the time for every page in the cache
                                }
                                else
                                {	
                                       	tracking[k] = 0; //if n is already in the cache then reset it's timer to 0
					clone = true;  
                                }       
                        }
			//print(cache,tracking); 
			if(clone == false)
			{
				fault = true; 
				for(int f = 0; f < cache.size(); f++)
				{ 
				
					if(tracking[f]  > temp)
					{
						max  = f;	//gets which spot where the page has been in the cache the longest
						temp = tracking[f];  
					}  	
				}
				cache[max] = n; //replace the oldest page with n
				tracking[max] = 0; //set the counter equal to zero because n has just entered the cache
				if(fault == true)
				{
					num_faults++;  
					cout << n << endl;
				}
				//print(cache,tracking); 
			}
		}
	i++; 	 
	}
	cout << "The Number of Page Faults:  " << num_faults << endl; 
}






















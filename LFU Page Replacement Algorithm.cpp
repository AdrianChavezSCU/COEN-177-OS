#include <iostream> 
#include <vector> 
#include <stdlib.h> 
#include <string>
#include <algorithm> 

using namespace std; 

void lru(int, vector<int>&, vector<int>&, vector<int>&); //run LRU  
void print(vector<int>, vector<int>, vector<int>); //print out what is in the 3 vectors to check each input
						  //only used this to test implementation 

void lru(int page, vector<int>& cache, vector<int>& tracking, vector<int>& frequency)
{
	int temp = 0; 
	int max = 0;
 	int n = page; 
	for(int x = 0; x < cache.size(); x++)
	{
		if(tracking[x]  > temp)
                {
                        max = x;
                	temp = tracking[x];
                }
	}
	cache[max] = n; 
	tracking[max] = 0; 
	frequency[max] = 0; 
}

void print(vector<int> cache, vector<int> tracking, vector<int> frequency)
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
	for(int i = 0; i < cache.size(); i++)
        {
                cout << frequency[i] << "  ";
        }	
	cout << endl; 
	
}


int main(int argc, char* argv[])
{
  	int SIZE = atoi(argv[1]);
	int n = 0; 
	int i = 0;
	int num_faults = 0; 
        vector<int> cache(SIZE); //vector that contains all the pages 
	vector<int> tracking(SIZE); //vector to keep track of how much time the page has been in the cache
	vector<int> frequency(SIZE); //keeps track of how frequent a page in the cache is used 
        while(!cin.eof())
        {
		bool faults = true;
		cin >> n; 
 	        if(i < cache.size())
                { 
			for(int k = 0; k < i; k++)
                        {
                              	if(cache[k] != n) //checking to see if n is already in the cache
                              	{
                                	tracking[k] += 1; //increment the time for what is already in the cache that is not n   
                              	}
                              	else
                              	{
                                        frequency[k] += 1; //increment frequency because n is already in the cache
                                        tracking[k] = 0; //reset the timer for n because it's already in the cache 
                              	}
                        }
			num_faults++; 
			cache[i] = n; 
			i++; 
		//	print(cache,tracking,frequency);
		}
        	else		//do this when the cache is already full 
        	{
                               	bool clone = false; //bool to check if n is already in the cache 
				bool check_recent = false;   

                                for(int k = 0; k < cache.size(); k++)
                                {
                                        if(cache[k] != n)
                                        {
                                                tracking[k] += 1; //increment time for what is already in the cache that is not n
                                        }
                                        else
                                        { 
				            	frequency[k] += 1; //increment frequency because n is already in the cache
                                                tracking[k] = 0; //reset the timer for n because it is already in the cache
                                                clone = true; 
                                        }
                                }
			//	print(cache,tracking,frequency); 
                                if(clone == false) //if n is not in the cache already do this
                                { 
                                        for(int f = 0; f < cache.size(); f++)
                                        {
						
						for(int g = 0; g < cache.size(); g++)
						{
							if(frequency[f] == frequency[g] && f != g)
							{
								check_recent = true; //There are two pages with same frequency
							}
						}
					}
					if(check_recent == true) //if there was a tie for frequency do this 
					{
						lru(n,cache,tracking,frequency); //run LRU to get rid of the tie in frequency 
						cout << n << endl; 
						num_faults++;
					//	print(cache,tracking,frequency);
					}
					else
					{
						for(int h = 0; h < cache.size(); h++)
                                		{
                                        		if(cache[h] != n)
                                        		{
                                                		tracking[h] += 1;
                                        		}
                                        		else
                                        		{
                                                		frequency[h] += 1;
                                                		tracking[h] = 0;
                                        		}
                                		}
						if(faults == true)
						{ 
                                			cache[i] = n;
							i++; 
						}
					//	print(cache,tracking,frequency);
						
					}
                                }
                    } 
	}
	cout << "Number of page faults: " << num_faults << endl; 
}

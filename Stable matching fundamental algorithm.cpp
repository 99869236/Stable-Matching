//stable matching project fundamental algorithm 159.333
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  
// Number of Men or Women,
const int n = 6;
  
// This function is to check woman prefer suitor or her fiance,w is woman,m1 is suitor,m2 is her fiance
//this function return true when w prefer her fiance,false when w prefer suitor
bool wPrefersM1OverM(int Prefer[n][n], int w, int m1, int m2) 
{ 
    //one by one go through the preference list of w
    for (int i = 0; i < n; i++) 
    { 
        //return true if m2 rank higher than m1
        if (Prefer[w][i] == m2) 
            return true; 
  
        //return false if m1 rank higher than m2 
        if (Prefer[w][i] == m1) 
           return false; 
    } 
} 
  
//this function implement fundamental algorithm to get stable matching
void stableMatching(int mPrefer[n][n],int wPrefer[n][n]) 
{ 
    //number of couples already formed
	int k = 0;
	//suitor
	int X;
	//woman toward whom the suitor makes advances
	int x;
	//imaginary man  
	int o = -1;
    //the partner of each woman
	int wPartner[n];
	//contain information about whether man is free or not
    bool mFree[n]; 
  
	//all the woman are temporarily engaged to the imaginary man
	//set all man be free 
	for (int i = 0; i < n; i++) {
		wPartner[i] = o;
		mFree[i] = true;
	}


  
    // While there are free men 
    while (k < n) 
    { 
		
		
        // Pick the first free man X
		int a;
        for ( a = 0; a < n; a++) 
            if (mFree[a] == true)				
                break; 
				X = a;

        //while X not equal to o,find the best choice remaining on X's list
		while (X != o) {
			for (int i = 0; i < n && mFree[X] == true; i++)
			{
				//the best choice remaining on X's list
				x = mPrefer[X][i];

				//if woman is free they become engaged
				//set the man is not free
				if (wPartner[x - n] == -1)
				{
					wPartner[x - n] = X;
					mFree[X] = false;
					break;
				}

				else   
				{   // If w is not free
					// Find current partner of the woman
					int cur = wPartner[x - n];

					//x prefer X to her fiance, set fiance be free and engaged with X  
					if (wPrefersM1OverM(wPrefer, x, X, cur) == false)
					{
						wPartner[x - n] = X;
						mFree[X] = false;
						mFree[cur] = true;
						break;
					}
				} 
				
			}
			break;
		}
		//withdraw woman from men's preference
		if (X < n) {
			for (int i = 0; i < n - 1; i++) {
				mPrefer[X][i] = mPrefer[X][i + 1];
			}
		}
		k++;
    } 
  
  
    // the output of the program 
	// the left column is the list of man, the right colunm is their partner
    cout << "Man   Woman" << endl; 
    for (int i = 0; i < n; i++) 
       cout << " " << wPartner[i] << "\t" << i+n << endl;
} 
  
// get input and implement functions 
int main() 
{ 
	//the input of n=6 man or woman
	//men's preference
	int mPrefer[n][n] = {
		  {6, 7, 8, 9, 10, 11},
		{6, 7, 8, 9, 10, 11},
		{6, 7, 8, 9, 10, 11},
		{6, 7, 8, 9, 10, 11},
		  {6, 7, 8, 9, 10, 11},
		  {6, 7, 8, 9, 10, 11},
	};
	//women's preference
	int wPrefer[n][n] = {
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		  {0,1,2,3,4,5},
	};
	//stable matching the input groups of man and woman
	stableMatching(mPrefer, wPrefer);
  
    return 0; 
}
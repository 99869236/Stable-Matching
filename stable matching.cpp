//stable matching project fundamental algorithm 159.333

#include <iostream> 
#include<fstream>
#include <string> 



using namespace std; 

  

// Number of Men or Women,

const int n = 6;

// This function is to check woman prefer suitor or her fiance,w is woman,m1 is suitor,m2 is her fiance

//this function return true when w prefer her fiance,false when w prefer suitor

bool wPrefersM1OverM2(int Prefer[2*n][n], int w, int m1, int m2) { 

    //one by one go through the preference list of w

    for (int i = 0; i < n; i++) {
        //return true if m1 rank higher than m2 
        if (Prefer[w][i] == m2) 
           return true; 
		  //return false if m2 rank higher than m1
        if (Prefer[w][i] == m1)
            return false; 
	} 

} 

//this function implement fundamental algorithm to get stable matching

void stableMatching(int mPrefer[2*n][n]) 

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

    while (k < n) { 
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
					k++;
				}
				else   

				{   // If w is not free

					// Find current partner of the woman

					int cur = wPartner[x - n];
					//x prefer X to her fiance, set fiance be free and engaged with X  

					if (wPrefersM1OverM2(mPrefer, x, X,cur) == false){
						
						wPartner[x - n] = X;
						mFree[X] = false;
						mFree[cur] = true;
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

	//line 1 to 6 is men's preference
	//line 7 to 12 is woman's preference

	/*int mPrefer[2*n][n] = {
        {9, 7,8,6,11,10}, 

		  {6, 7,8,9,10,11},

		  {7, 6,8,9,10,11},

        {7, 6,9,8,10,11}, 

        {10, 11,8,9,6,7}, 

        {6, 11,8,9,10,7},
		  {2, 0, 1, 3,4,5},

        {0, 1, 2, 3,4,5},

        {3, 1, 2, 0,4,5}, 

		  {3, 2, 1, 0,4,5},

		  {4, 1, 0, 3,2,5},

		  {4, 1, 0, 3,2,5},
		  
	};*/


	int prefer[2*n][n];
	ifstream file("data.txt");
	
	if(file.is_open()) {
	   for(int i=0;i<2*n;i++){
		   for(int j=0;j<n;j++){
			   file>>prefer[i][j];
		   }
	   }
	}else{
		cout<<"Unable to open file";
		
	}	

	file.close();

	//stable matching the input groups of man and woman

	stableMatching(prefer);

  

    return 0; 

}
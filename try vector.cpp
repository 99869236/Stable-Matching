//stable matching project fundamental algorithm 159.333

#include <iostream> 
#include<fstream>
#include <string> 
#include<vector>


using namespace std; 

  

// Number of Men or Women,

const int n = 6;

// This function is to check woman prefer suitor or her fiance,w is woman,m1 is suitor,m2 is her fiance

//this function return true when w prefer her fiance,false when w prefer suitor

bool wPrefersM1OverM2(vector<int> Prefer, int w, int m1, int m2) { 

    //one by one go through the preference list of w
int p;//position in vector;
    for (int i = 0; i < n; i++) {
    	p=(w*6)+i;
        //return true if m1 rank higher than m2 
        //if (Prefer[w][i] == m2) 
         if(Prefer.at(p)==m2){
           return true; 
		   }  
		  //return false if m2 rank higher than m1
        //if (Prefer[w][i] == m1)
         if(Prefer.at(p)==m1) {
            return false; 
			}	
	} 

} 

//this function implement fundamental algorithm to get stable matching

void stableMatching(vector<int> mPrefer) 

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

/*cout << "Output of begin and end: "; 
    for (auto i = mPrefer.begin(); i != mPrefer.end(); ++i) 
        cout << *i << " "; 
	*/      
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
				//cout<<X;
        //while X not equal to o,find the best choice remaining on X's list

		//while (X != o) {

			for (int i = 0; i < n && mFree[X] == true; i++){
				//the best choice remaining on X's list
				int p;//the position in vector mPrefer
				p=X*6+i;
				//cout<<p<<" ";
				x =mPrefer.at(p);
				//cout<<x;
				//if woman is free they become engaged
				//set the man is not free
				if (wPartner[x - n] == -1)
				{
					//cout<<"aaa";
					wPartner[x - n] = X;
					mFree[X] = false;
					k++;
					//cout<<k;
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

			
		//}

		

    }
    // the output of the program 

	// the left column is the list of man, the right colunm is their partner

    cout << "Man   Woman" << endl; 

    for (int i = 0; i < n; i++) 

       cout << " " << wPartner[i] << "\t" << i+n << endl;
} 

  

// get input and implement functions 

int main() { 
	//the input of n=6 man or woman

vector<int> prefer;

	ifstream file("data.txt");
	int a;
	if(file.is_open()) {
	   for(int i=0;i<2*n;i++){
		   for(int j=0;j<n;j++){
			   file>>a;
			   prefer.push_back(a); 
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
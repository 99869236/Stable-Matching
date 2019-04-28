#include <vector>
#include <iostream> 
#include <string> 
#include <fstream>

using namespace std;

const int n=6;

class Match{
public:
	Match(){}
	void setPrefer(ifstream& inf);	
	void stableMatching(vector<int> mPrefer);	
	vector<int> getPrefer(){return prefer;}	
private:
	vector<int> prefer;
   int partner[n];
   bool free[n]; 
};
void Match::setPrefer(ifstream& inf){
	int a;
	if(inf.is_open()) {
	   for(int i=0;i<2*n;i++){
		   for(int j=0;j<n;j++){
			   inf>>a;
			   prefer.push_back(a); 
		   }
	   }
	}else{
		cout<<"Unable to open file";
	}	
	inf.close();
}


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

void Match::stableMatching(vector<int> mPrefer){
	//number of couples already formed
	int k = 0;
	//suitor
	int X;
	//woman toward whom the suitor makes advances
	int x;
	//imaginary man  
	int o = -1;
	for (int i = 0; i < n; i++) {
		partner[i] = o;
		free[i] = true;
	}
    // While there are free men 
    while (k < n) { 
        // Pick the first free man X
		int a;
        for ( a = 0; a < n; a++) 
            if (free[a] == true)				
                break; 
				X = a;
				//cout<<X;
        //while X not equal to o,find the best choice remaining on X's list
		//while (X != o) {
			for (int i = 0; i < n && free[X] == true; i++){
				//the best choice remaining on X's list
				int p;//the position in vector mPrefer
				p=X*6+i;
				//cout<<p<<" ";
				x =mPrefer.at(p);
				//cout<<x;
				//if woman is free they become engaged
				//set the man is not free
				if (partner[x - n] == -1)
				{
					//cout<<"aaa";
					partner[x - n] = X;
					free[X] = false;
					k++;
					//cout<<k;
				}
				else   
				{   // If w is not free
					// Find current partner of the woman
					int cur = partner[x - n];
					//x prefer X to her fiance, set fiance be free and engaged with X  
					if (wPrefersM1OverM2(mPrefer, x, X,cur) == false){
						partner[x - n] = X;
						free[X] = false;
						free[cur] = true;
					}
				}
			}
    }
    // the output of the program 

	// the left column is the list of man, the right colunm is their partner
    cout << "Man   Woman" << endl; 
    for (int i = 0; i < n; i++) 
       cout << " " << partner[i] << "\t" << i+n << endl;
} 

int main(){
	Match m;
	ifstream file("data.txt");
	m.setPrefer(file);
	m.stableMatching(m.getPrefer());
}
	

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class state{
	private:
		int n_alphabet;
		string alphabet;
		int* edges;
		bool isFinal;
		bool isInitial;
	public:
		state(string alphabets){
			isFinal = false;
			isInitial = false;
			n_alphabet = alphabets.length();
			alphabet = alphabets;
			edges = new int[n_alphabet];
			for(int i = 0 ; i <n_alphabet;i++){
				edges[i] = 0;
			}
		}
		void setEdge(int i,int val){
			edges[i] = val;
		}
		void setFinal(){
			isFinal = true;
		}
		void setInitial(){
			isInitial = true;
		}
		bool IsInitial(){
			return isInitial;
		}
		bool IsFinal(){
			return isFinal;
		}
		int nextState(char i){
			int index = 0;
			for(int j = 0 ; j < n_alphabet ;j++){
				if(alphabet[j] == i){
					index = j;
				}
			}
			return edges[index];
		}
		void print_info(){
			for(int i = 0 ; i < n_alphabet;i++){
				cout << edges[i] << "\t";
			}
			if(isInitial){
				cout << "I";
			}
			if(isFinal){
				cout << "F";
			}
		}
		
};
class DFA{
	private:
		int n_states;
		int n_alphabets;
		vector<state> states;
		string alphabet;
	public:
		DFA(int n,string a){
			n_states = n;
			n_alphabets = a.length();
			alphabet = a;
			for(int i = 0 ; i < n_states;i++){
				state newstate(alphabet);
				if(i == 0){
				newstate.setInitial();}
				states.push_back(newstate);
			}
			system("cls");
			Draw_TransitionTable();
			SetFinal();
		}
		void Draw_TransitionTable(){
			cout<<endl<<"\t"<<"STATE"<<"\t";
			for(int i = 0 ; i < n_alphabets ; i++){
				cout << alphabet[i] << "\t";
			}
			cout << endl<< endl <<"\t";
			for(int i = 0 ; i < n_states;i++){
				cout << i << "\t";
				states.at(i).print_info();
				cout << endl<<"\t";
			}
		}
		void SetFinal(){
			cout <<endl<<"Which state would you like to set as final(initial state is 0): ";
			int x;
			cin >> x;
			states.at(x).setFinal();
		}
		void SetEdges(){
			cout <<endl<<"Fill up the transition table:" << endl;
			for (int i = 0 ; i < n_states;i++){
				cout <<"FOR STATE " << i << " : "<< endl;
				for(int j = 0 ; j < n_alphabets;j++){
					int x;
					cout <<"Enter destination state for alphabet " << alphabet[j] << " : ";
					cin >> x;
					states.at(i).setEdge(j,x);
					cout << endl; 
				} 
				system("CLS");
				Draw_TransitionTable();
			}
		}
		void Parse(string x){
			int currentState = 0;
			char currentCharacter = x[0];
			for(int i = 0 ; i < x.length() ;i++){
				currentState = states.at(currentState).nextState(currentCharacter);
			}
			if(states.at(currentState).IsFinal()){
				cout <<"ACCEPTED" << endl;
			}
			else{
				cout <<"REJECTED" << endl;
			}
		}
};
int main(){
	while(1){
	int n1;
	int n2;
	string alphabets = "";
	string test;
	cout <<"Distinct Finite Automata Simulation"<<endl<<"Assignment CS224"<<endl<<"Submitted to Sir Ehtisham"<<endl<<"Submitted by Hanzla Javaid - 2018271" << endl << endl;
	cout <<"Enter number of States : ";
	cin >> n1;
	cout <<"Enter number of Alphabets : "; 
	cin >> n2;
	for(int i = 0 ; i < n2 ;i++){
		char x;
		cout <<"Enter Alphabet number "<<i<<" : ";
		cin >> x;
		alphabets+=x;
	}
	DFA dfa(n1,alphabets);
	dfa.Draw_TransitionTable();
	dfa.SetEdges();
	while(1){
		char check;
		cout << endl <<"Enter string to be parsed : ";
		cin >> test;
		dfa.Parse(test);
		cout <<"Enter N to try new string , D to create new DFA , C to close program : ";
		cin >> check;
		if(check == 'C'){
			return 0;
		}
		if(check == 'D'){
			system("cls");
			break;
		}
		if(check == 'N'){
			continue;
		}
	}
}
}

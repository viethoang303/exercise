#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

const int MAX_BAD_WORD = 7;
const char DATA_LIST[] = "listWords.txt";

string chooseWord(const char* fileName);
void print(char a, string guessWord);
char guess();
string update(string word, string guessWord, char a);
bool contains(string word, char a);
void renderGame(string guessedWord, int dem1);
string playagain()
{
    string s;
    cin >> s;
    return s;
}
void Main();
int main ()
{
    srand(time(0));
    int dem1 = 0;
    string word = chooseWord(DATA_LIST);
    string guessWord = string(word.length(), '_');
    int doandung = 0;
    do {
        renderGame( guessWord, dem1);
        char a = guess();
        if(contains(word, a)){
            guessWord = update(word, guessWord, a);
            system("cls");
        } else {
            system("cls");
            dem1++;

        }
    } while (dem1<MAX_BAD_WORD && word!=guessWord);
    renderGame( guessWord, dem1);
    if (dem1<MAX_BAD_WORD){
        cout << "Congratulations. You win!!!!" << endl;
    } else {
        cout << "You lose. The correct word is: " << word << endl;
    }
    string s;
    if (word==guessWord){
        cout << "Do you want to play again???" << endl;
        s = playagain();
    }
    if (s=="yes"){
        system("cls");
        Main();
    }
    return 0;
}
void Main()
{
    srand(time(0));
    int dem1 = 0;
    string word = chooseWord(DATA_LIST);
    string guessWord = string(word.length(), '_');
    int doandung = 0;
    do {
        renderGame( guessWord, dem1);
        char a = guess();
        if(contains(word, a)){
            guessWord = update(word, guessWord, a);
            system("cls");
        } else {
            system("cls");
            dem1++;

        }
    } while (dem1<MAX_BAD_WORD && word!=guessWord);
    renderGame( guessWord, dem1);
    if (dem1<MAX_BAD_WORD){
        cout << "Congratulations. You win!!!!" << endl;
    } else {
        cout << "You lose. The correct word is: " << word << endl;
    }
    string s;
    if (word==guessWord){
        cout << "Do you want to play again???" << endl;
        s = playagain();
    }
    if (s=="yes"){
        system("cls");
        Main();
    }
}
string chooseWord(const char* fileName)
{
    vector<string> List;
    ifstream file(fileName);
    if (file.is_open()){
        string word;
        while (file >> word){
            List.push_back(word);
        }
        file.close();
    }
    if (List.size()>0){
        int Size = List.size();
        int b = rand()%Size;
        return List[b];
    } else return "";
}
const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
void renderGame(string guessWord, int dem1)
{
	cout << FIGURE[dem1] << endl;
    cout << guessWord << endl;
	cout << "Number of wrong guesses: " << dem1 << endl;
}

void print(char a, string guessWord)
{
    cout << guessWord << endl;
}
char guess()
{
    cout << "Your guess: ";
    char a;
    cin >> a;
    return a;
}
string update(string word, string guessWord, char a)
{
    for(int i=0; i<word.size(); i++){
        if(word[i]==a){
            guessWord[i] = a;
        }
    }
    return guessWord;
}
bool contains(string word, char a)
{
    int dem = 0;
    for (int i=0; i<word.size(); i++){
        if (word[i]==a) dem++;
    }
    if(dem!=0){
        return true;
    } else {
        return false;
    }
}

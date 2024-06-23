#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void displayQuestion(int index, const string& text, const string options[], char correctAnswer) {
    cout << index + 1 << ". " << text << endl;
    for (int i = 0; i < 4; ++i) {
        cout<< "   "<<static_cast<char>('A' + i)<< ". "<< options[i]<< endl;
    }
    cout<<endl;
}


char getUserAnswer() {
    cout<<"Your answer (A, B, C, or D): ";
    char answer;
    cin>>answer;
    return toupper(answer);
}


bool evaluateAnswer(char userAnswer, char correctAnswer)
{
    return userAnswer == correctAnswer;
}


void displayResult(int score, int totalQuestions)
 {
    double percentage = static_cast<double>(score) / totalQuestions * 100;
    cout<<"\nYour score: "<<score<< "/" << totalQuestions<< " (" << fixed << setprecision(2)<< percentage<< "%)\n";
}


void takeQuiz(const string questions[], const string options[][4], const char correctAnswers[]) {
    const int totalQuestions = 10;
    int score = 0;

    for (int i = 0; i < totalQuestions; ++i) {
        displayQuestion(i, questions[i], options[i], correctAnswers[i]);

        while (true) {
            char userAnswer = getUserAnswer();
            if (userAnswer >= 'A' && userAnswer <= 'D') {
                if (evaluateAnswer(userAnswer, correctAnswers[i])) {
                    cout << "Correct!\n\n";
                    score++;
                    break;
                } else {
                    cout << "Incorrect!. .\n\n";
                    
                }
            } else {
                cout << "Invalid input. Please enter A, B, C, or D.\n";
            }
        }
    }

    displayResult(score, totalQuestions);
}

int main() 
{
    
    string questions[10] = {
    	//Classic Litterature
        "Who is the author of War and Peace?",
        "who is Main character in No Longer Human??",
        "Who is the god of tolkien world of arda?",
        "Who is the writter of Tale of the Two cities?",
        "Who wrote 'Romeo and Juliet'? ",
        //Manga
        "Who is the main Character the black sword man in berserk?",
        "Who is the mangaka wrote the Attack on titan?",
        "Who si The godfather of manga?",
        "she is The Creator of kaze to ko no uta?"
        "Who is the mangaka and Creator of Dragon Ball?"
        
        
        
    };

    string options[10][4] = {
        {"[A]Leo tolstoy", "[B]fyodor dotivesky", "[C]osamu Dazai", "[D]Edgar Allan Poe?"},
        {"[A]Samwise Gamgee", "[B]Oba Yozo", "[C]Xie Lian", "[D]Sherlock Holmes"},
        {"[A]Gladiriel", "[B]Eru Illuvitar", "[C]Morgoth", "[B]Ungoliath"},
        {"[A]Charles Dickens","[B]JRR Tokien","[C]Paulo coelho","[D]Franz Kafka"},
        {"[A]Jane Austen","[B]Bram Strocker","[C]William Shakespeare","[D]Oscar Wilde"},
        {"[A]Grunbled","[B]Casca","[C]Griffith","[D]Guts"},
		{"[A]Akira kurosawa", "[b]Conan Edogawa","[C]Isayama Hajime","[D]Narita Youngo"},
		{"[A]Isamu Tenzuka","[b]miamura kentaro","[C]Matsi yusei","[D]Akira kurosawa"},
		{"[A]Go Nagai","[B]Tekimiya keiko","[C]Moto Haigo","[D]Riyoko Ikeda"},
		{"[A]Noako Takeuchi","[B]Noaki Kurosawa","[C]YAmto Nagao","[D]Akira Torimiya"},
	
    };

    char correctAnswers[10] = {'A', 'B', 'B', 'A', 'C', 'D', 'C', 'A', 'B', 'D'};
    
    
    takeQuiz(questions, options, correctAnswers);
    
}

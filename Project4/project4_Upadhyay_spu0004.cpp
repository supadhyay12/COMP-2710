/** File: project4_Upadhyay_spu0004.cpp
  * Author: Shanti Upadhyay
  * Auburn ID: 903998817
  * IDE: jGrasp, Compiled with g++
  **Important!: Unable to upload to AU Server. Asked TA Tian Liu for solutions but
  *             they did not work. 
  * No help received on Project 4. 
  *
  **/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

using namespace std;

// linked list that holds a trivia question, answer, and point amount
struct TriviaNode {
    string question;
    string answer;
    int point;
    TriviaNode *next;
};

// trivia questions
void question_list(TriviaNode &tn1, TriviaNode &tn2, TriviaNode &tn3) {
    tn1.question = "How long was the longest war on record? (Hint: how many minutes)";
    tn1.answer = "38";
    tn1.point = 100;
    tn1.next = &tn2;

    tn2.question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    tn2.answer = "Bank of Italy";
    tn2.point = 50;
    tn2.next = &tn3;

    tn3.question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    tn3.answer = "Wii Sports";
    tn3.point = 20;
    tn3.next = NULL;
}

void input_question(TriviaNode *head) {
        string cont;
        do {
            TriviaNode *next = new TriviaNode;
            while (next->question == "") 
            {
                cout << "Enter a question: ";
                getline(cin, next->question);
            }
            while (next->answer == "") 
            {
                cout << "Enter the answer: ";
                getline(cin, next->answer);
            }
            cout << "Enter award points: ";
            cin >> next->point;
            while (cin.fail()) 
            {
                cin.clear();
                cin.ignore();
                cout << "Please enter an integer value." << endl;
                cin >> next->point;
            }
            cin.ignore();
            next->next = NULL;

            if (head->question == "") {
                *head = *next;
            }
            else {
                TriviaNode *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = next;
            }
            cout << "Continue? (Yes/No): ";
            getline(cin, cont);
            transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
            while (cont != "yes" && cont != "no") 
            {
                cout << "Please enter \"Yes\" or \"No\"" << endl;
                getline(cin, cont);
                transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
            }
        } 
        while (cont == "yes");
}

// check num of questions
int questionNum(TriviaNode *head) {
    int length = 0;
    TriviaNode *current = head;
    while (current != NULL) 
    {
        length++;
        current = current->next;
    }
    return length;
}

int ask_question(TriviaNode *head, int num_ask) {
    int numPoints = 0;

    if (head == NULL)
        return 0;
    if (num_ask < 1) {
        cout << "Warning - the number of trivia questions to be asked must be equal to or be larger than 1.";
    }
    else if (questionNum(head) < num_ask) {
        cout << "Warning - There is only " << questionNum(head) << " trivia questions in the list.";
    }
    else {
        string user_answer;

        TriviaNode *currentParam = head;
        for (int i = 0; i < num_ask; i++) {
            cout << "Question: " << currentParam->question << endl;
            cout << "Type Your Answer: ";
            getline(cin, user_answer);
            if (user_answer.compare(currentParam->answer) == 0) 
            {
                cout << "Correct! You are awarded " << currentParam->point << " points." << endl;
                numPoints += currentParam->point;
            }
            else {
                cout << "That answer is wrong. The correct answer is " << currentParam->answer << endl;
            }
            currentParam = currentParam->next;
            cout << "\nYour total points: " << numPoints << endl;
        }
    }
    return numPoints;
}

// unit test cases
void Unit_Test() {
    cout << "*** This is a debugging version ***\n";

    int totalPoints = 0;
    TriviaNode tn1, tn2, tn3;
    question_list(tn1, tn2, tn3);

    cout << "Unit Test Case 1; Ask no question. The program should give a warning message." << endl;
    ask_question(&tn1, 0);
    cout << "\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    totalPoints = ask_question(&tn1, 1);
    assert(totalPoints == 0);
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    totalPoints = ask_question(&tn1, 1);
    assert(totalPoints != 0);
    cout << "\nCase 2.2 Passed\n\n";

    cout << "Unit Test Case 3: Ask all the questions in the linked list." << endl;
    totalPoints = ask_question(&tn1, 3);
    assert(totalPoints != 0);
    cout << "\nCase 3 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list" << endl;
    totalPoints = ask_question(&tn1, 5);
    assert(totalPoints == 0);
    cout << "\nCase 4 Passed\n\n";

    cout << "\n\n*** End of the Debugging Version ***" << endl;
}

#define UNIT_TESTING

int main() {

#ifdef UNIT_TESTING
    Unit_Test();
    return 0;

#else
    int totalPoints = 0;
    string input;
    int questionNum;
    TriviaNode tn1, tn2, tn3;
    question_list(tn1, tn2, tn3);

    cout << "*** Welcome to Shanti's trivia quiz game ***\n";

    cout << "Would you like to add a question? (Yes/No)" << endl;
    getline(cin,input);

    if(input == "Yes" || "yes")  {
         input_question(&tn1);
    }

    cout << "How many questions would you like to answer? " << endl;
    cin >> questionNum;
    cin.ignore();
    ask_question(&tn1, questionNum);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    return 0;

#endif
}
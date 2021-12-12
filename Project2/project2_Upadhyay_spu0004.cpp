/** File: project2_Upadhyay_spu0004.cpp
  * Author: Shanti Upadhyay
  * Auburn ID: 903998817
  * IDE: jGrasp, Compiled with g++
  **Important!: Unable to upload to AU Server. Asked TA Tian Liu for solutions but
  *             they did not work. 
  * No help received on Project 2. 
  *
  **/
  
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

const int TOTAL_RUNS = 10000; // constant variable for total runs

// implement "enter to continue"
void press_enter_key(void) {
    cout << "Press Enter to continue...";
    cin.ignore().get();
}

bool A_alive; 
bool B_alive; 
bool C_alive;

void test_two_alive(void);
void test_Aaron_shoots1(void);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void test_Bob_shoots(void);
void Bob_shoots(bool& A_alive, bool& C_alive);
void test_Charlie_shoots(void);
void Charlie_shoots(bool& B_alive, bool& C_alive);
void test_Aaron_shoots2(void);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);


int main(){

//amount of duels won per strategy
	double a = 0; 
   double b = 0; 
   double c = 0; 
	
   double shootStrategy1 = 0; 
   double shootStrategy2 = 0;
	
	cout << "*** Welcome to Shanti's Duel Simulator ***" << fixed << endl;
	
   // random number generator
	srand(time(0));

	test_two_alive();
	test_Aaron_shoots1();
	test_Bob_shoots();
	test_Charlie_shoots();
	test_Aaron_shoots2();

	cout.precision(2);

	cout << "Ready to test strategy 1 (run " << TOTAL_RUNS << " times):\n";
   press_enter_key();

	cout << "\n";
	
	for (int i = 0; i < TOTAL_RUNS; i++){

	A_alive = true;
	B_alive = true;
	C_alive = true;

	while (at_least_two_alive(A_alive, B_alive, C_alive)){
		
      if (A_alive) { 
         Aaron_shoots1(B_alive, C_alive); }
		if (at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) { 
         Bob_shoots(A_alive, C_alive); }
		if (at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) { 
         Charlie_shoots(A_alive, B_alive); }
	}
	
	if (A_alive) {
      a++;
   }
	if (B_alive) {
      b++;
   }
	if (C_alive) {
      c++;
   }	

 }

	shootStrategy1 = (a / 100);

	cout << "Aaron won " << a << "/" << TOTAL_RUNS << " duels or " << shootStrategy1 << "%\n";
	cout << "Bob won " << b << "/" << TOTAL_RUNS << " duels or " << (b/100.0) << "%\n";
	cout << "Charlie won " << c << "/" << TOTAL_RUNS << " duels or " << (c/100.0) << "%\n\n";

	cout << "Ready to test strategy 2 (run " << TOTAL_RUNS << " times):\n";
   press_enter_key();

	cout << "\n";

//reset values of a, b, c for new shoot strategy
	a = 0;
	b = 0;
	c = 0;

	for (int i = 0; i < TOTAL_RUNS; i++){

		A_alive = true;
		B_alive = true;
		C_alive = true;

		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) {
            Aaron_shoots2(B_alive, C_alive); 
         }
			if (at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) {
            Bob_shoots(A_alive, C_alive); 
         }
			if (at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) {
            Charlie_shoots(A_alive, B_alive); 
         }
		}

		if (A_alive) {
         a++;
      }
		if (B_alive) {
         b++;
      }
		if (C_alive) {
         c++;
      }

	}

	shootStrategy2 = (a / 100);
			
	cout << "Aaron won " << a << "/" << TOTAL_RUNS << " duels or " << shootStrategy2 << "%\n";
	cout << "Bob won " << b << "/" << TOTAL_RUNS << " duels or " << (b/100.0) << "%\n";
	cout << "Charlie won " << c << "/" << TOTAL_RUNS << " duels or " << (c/100.0) << "%\n";
	
	if (shootStrategy2 > shootStrategy1) {
      cout << "\nStrategy 2 is better than strategy 1.\n";
   }
	else {
      cout << "\n Strategy 1 is better than strategy 2.\n";
   }

}

void test_two_alive(void){

	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\t Case passed ...\n";
	
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\t Case passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\t Case passed ...\n";

	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\t Case passed ...\n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\t Case passed ...\n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\t Case passed ...\n";

	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\t Case passed ...\n";

	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\t Case passed ...\n";

   press_enter_key();
}

void test_Aaron_shoots1(void){

	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	
   cout <<"\tCase 1: Bob alive, Charlie alive\n";
   B_alive = true;
   C_alive = true;
   Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n";
	B_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 3: Bob alive, Charlie dead\n";
	B_alive = true;
	C_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Bob\n";

   press_enter_key();
}

void test_Bob_shoots(void){

	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
	
   cout << "\tCase 1: Aaron alive, Charlie alive\n";
	Bob_shoots(A_alive,C_alive);
   A_alive = true;
   C_alive = true;
	cout << "\t\tBob is shooting at Charlie\n";
	
	cout << "\tCase 2: Aaron dead, Charlie alive\n";
	A_alive = false;
	Bob_shoots(A_alive, C_alive);
	cout << "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 3: Aaron alive, Charlie dead\n";
	A_alive = true;
	C_alive = false;
	Bob_shoots(A_alive, C_alive);
	cout << "\t\tBob is shooting at Aaron\n";


   press_enter_key();
}

void test_Charlie_shoots(void){

	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	
   cout << "\tCase 1: Aaron alive, Bob alive\n";
   A_alive = true;
   B_alive = true;
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Bob\n";

	cout << "\tCase 2: Aaron dead, Bob alive\n";
	A_alive = false;
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Bob\n";

	cout << "\tCase 3: Aaron alive, Bob dead\n";
	A_alive = true;
	B_alive = false;
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Aaron\n";	

   press_enter_key();
}

void test_Aaron_shoots2(void){

	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
	
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   B_alive = true;
	C_alive = true;
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron intentionally misses his first shot\n\t\tBoth Bob and Charlie are alive\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n";
	B_alive = false;
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 3: Bob alive, Charlie dead\n";
	B_alive = true;
	C_alive = false;
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Bob\n";

   press_enter_key();

}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){

	if(A_alive){
		if(B_alive){ 
         return true; 
      }
		if(C_alive){ 
         return true; 
      }
	}
	if(B_alive && C_alive) {
      return true;
   }

	return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {

	double shootResult = rand()%100;
	
	if(shootResult < 33.33) { // only hit target with prob of 1/3
	
		if(C_alive) { 
         C_alive = false; 
      }
		else { 
         B_alive = false; 
      }
	}

}

void Bob_shoots(bool& A_alive, bool& C_alive){


	double shootResult = rand()%100;

	if(shootResult < 50) { // hit target with probability of 1/2

		if(C_alive) {
         C_alive = false;
      }
		else {
         A_alive = false;
      }
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive){
// no shootResult due to Charlie never missing a hit

	if(B_alive) {
      B_alive = false;
   }
	else {
      A_alive = false;
   }
}


void Aaron_shoots2(bool& B_alive, bool& C_alive){

	if((B_alive && C_alive) == false){

		double shootResult = rand()%100;

		if (shootResult < 33.33){

			if (C_alive){
            C_alive = false;
         }
			else {
            B_alive = false;
         }
		}
	}
}
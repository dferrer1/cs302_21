// Author: Diego Ferrer
// Challenge 08: Adding List-Based Integers
// Overview: This challenge was to add two numbers that are too large to store as integers. I did this by first getting the numbers in reverse so that I could add them starting
//			 from their least significant bit and calculate the carry. I would then print the reverse of this sum (which was already reversed) so that it was in the right order.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> sadd(stack<int> a, stack<int> b);

int main(int argc, char *argv[]) {
    int n;
	string num1, num2;

	// continually take input from the std input and store in strings
	while(cin >> num1 >> num2) {
		stack<int> s1, s2, sr;
		
		// convert first string into stacks of ints (little endian)
		for (size_t i = 0; i < num1.size(); i++) {
			n = num1[i] - '0';
			s1.push(n);
		}

		// convert second string into stacks of ints (little endian)
		for (size_t i = 0; i < num2.size(); i++) {
			n = num2[i] - '0';
			s2.push(n);
		}

		// call sadd with the first parameter being the larger sized stack
		if (s1.size() > s2.size()) {
			sr = sadd(s1, s2);
		} else {
			sr = sadd(s2, s1);
		}

		// print out the resulting stack in reverse 
		while(!sr.empty()) {
			cout << sr.top();
			sr.pop();
		}
		cout << endl;
		
	}
	
	return 0;
}

// sadd: takes two stacks of ints which represent integers (in little endian) that are too large to add otherwise and calculates their sum
//		a - larger sized stack
//		b - smaller sized stack
//		returns a stack of ints that is the sum of the stacks (in little endian)
stack<int> sadd(stack<int> a, stack<int> b) {
	stack<int> result;
	int tsum = 0;
	int sum = 0;
	int carry = 0;

	// add the smaller stack from its least significant bit
	while(!b.empty()) {
		// calculate the total sum, and from that, the current digit and the carry for the next digit
		tsum = (a.top() + b.top() + carry);
		sum = tsum % 10;
		carry = tsum / 10;

		// store the current digit in the result
		result.push(sum);

		// remove the current LSBs to get the next digits to add
		a.pop();
		b.pop();
	}

	// keep the values of the larger stack in the result
	while (!a.empty()) {
		// calculate the total sum, and from that, the current digit and the carry for the next digit
		tsum = (a.top() + carry);
		sum = tsum % 10;
		carry = tsum /10;

		// store the current digit in the result
		result.push(sum);

		// remove the current LSB to get the next digit
		a.pop();
	}
	
	// make sure that there is no final carry
	if (carry != 0) {
		result.push(carry);
	}

	return result;
}


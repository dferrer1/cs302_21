// Author: Diego Ferrer
// Challenge 08: Adding List-Based Integers
// Overview: 

#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

string add(queue<int> a, queue<int> b);
stack<int> sadd(stack<int> a, stack<int> b);

int main(int argc, char *argv[]) {
    int n;
	string num1, num2, result;

	// take input from the std input
	while(cin >> num1 >> num2) {
		queue<int> q1, q2;
		stack<int> s1, s2, sr;
		
		//DEBUG: check input
		//cout << "Input num1: " << num1 << " Input num2: " << num2 << endl;

		// convert strings into queues
		for (size_t i = 0; i < num1.size(); i++) {
			n = num1[i] - '0';
			//q1.push(num1[i]);
			
			//cout << num1[i] << " ";
			
			s1.push(n);
		}

		//DEBUG: debug formatting
		//cout << endl;
		
		for (size_t i = 0; i < num2.size(); i++) {
			n = num2[i] - '0';
			//q2.push(num2[i]);	
			
			//cout << num2[i] << " ";
			
			s2.push(n);
		}

		//DEBUG: debug formatting
		//cout << endl;
		
		if (s1.size() > s2.size()) {
			//result = add(q1, q2);
			sr = sadd(s1, s2);
		} else {
			//result = add(q2, q1);
			sr = sadd(s2, s1);
		}

		//DEBUG: debug formatting
		//cout << endl;
		
		//cout << "FINAL: ";
		while(!sr.empty()) {
			cout << sr.top();
			sr.pop();
		}
		cout << endl;
		
		//DEBUG: debug formatting
		//cout << "________________" << endl;
		/*
		//DEBUG: check queue values
		while(!s1.empty()) {
			cout << (char)s1.top();
			s1.pop();
		}
		cout << "   ";
		while(s2.size() != 0) {
			cout << (char)s2.top();
			s2.pop();
		}
		cout << endl;
		*/
		/*
		//DEBUG: check queue values
		while(!q1.empty()) {
			cout << (char)q1.front();
			q1.pop();
		}
		cout << " ";
		while(q2.size() != 0) {
			cout << (char)q2.front();
			q2.pop();
		}
		cout << endl;
		*/


	}
	
	return 0;
}

// sadd: takes two stack of ints of integers that are too large to add otherwise and calculates their sum
//		a - larger sized queue
//		b - smaller sized queue
//		returns a string of the sum of the queues
stack<int> sadd(stack<int> a, stack<int> b) {
	stack<int> result;
	int tsum = 0;
	int sum = 0;
	int carry = 0;

	while(!b.empty()) {
		tsum = (a.top() + b.top() + carry);
		sum = tsum % 10;
		carry = tsum / 10;

		//DEBUG
		//cout << "a.top(): " << a.top() << "; b.top(): " << b.top() << "; sum: " << sum << " ";
		
		result.push(sum);
		a.pop();
		b.pop();
		
		//DEBUG
		//cout << endl;
	}

	while (!a.empty()) {
		tsum = (a.top() + carry);
		sum = tsum % 10;
		carry = tsum /10;

		//DEBUG
		//cout << "a.top(): " << a.top() << "; sum: " << sum << " ";
		
		result.push(sum);
		a.pop();
		
		//DEBUG
		//cout << endl;
	}
	
	//DEBUG
	//cout << endl;
	
	if (carry != 0) {
		result.push(carry);
	}

	return result;
}

// add: takes two queues of ints of integers that are too large to add otherwise and calculates their sum
//		a - larger sized queue
//		b - smaller sized queue
//		returns a string of the sum of the queues
string add(queue<int> a, queue<int> b) {
	string result;
	//int carry = 0;

	while (!a.empty()) {
		if (a.size() > b.size()) {
			cout << (char)a.front() << " ";
			result.push_back(a.front()); 
			a.pop();
			b.pop();
		}
	}
	cout << endl;

	//for (size_t i = a.size()-1; i >= 0; i--) {
	//	if (i > b.size()) {
	//		result.push_back(a[i]);
	//	}
	//	cout << a[i] << " ";
	//}
	return result;
}

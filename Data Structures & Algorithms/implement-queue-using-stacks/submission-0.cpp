class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {

        // If s2 has elements, front is already there
        if (!s2.empty()) {
            int ans = s2.top();
            s2.pop();
            return ans;
        }

        // Move elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int ans = s2.top();
        s2.pop();

        return ans;
    }
    
    int peek() {

        // If s2 has elements, front is already there
        if (!s2.empty()) {
            return s2.top();
        }

        // Move elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
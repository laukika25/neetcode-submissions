class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int>st;
        for(int i = 0; i<operations.size(); i++){
            if(operations[i] == "D"){
                int x = st.top() * 2;
                st.push(int(x));
                sum += x;
            }
            else if(operations[i] == "C"){
                int removeitem = st.top();
                sum -= removeitem;
                st.pop();
            }
            else if(operations[i] == "+"){
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                int plus = one + two;
                st.push(two);
                st.push(one);
                st.push(int(plus));
                sum += plus; 
            }
            else{
                int score = stoi(operations[i]);

                st.push(score);
                sum += score;
            }
        }
        return sum;
    }
};
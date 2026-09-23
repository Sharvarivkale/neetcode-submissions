class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result;

        for(string token : tokens){
            if(token=="+" ||token=="*" ||token=="/" ||token=="-"){
                int b=st.top();
                st.pop();

                int a=st.top();
                st.pop();

                if(token=="+"){
                    result=a+b;
                }
                else if(token=="*"){
                    result=a*b;
                }
                else if(token=="/"){
                    result=a/b;
                }
                else if(token=="-"){
                    result=a-b;
                }
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
        
    }
};

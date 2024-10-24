#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Helper function to generate parentheses
void generateParenthesisHelper(int open, int close, string current, vector<string> &result)
{
    if (open == 0 && close == 0)
    {
        result.push_back(current);
        return;
    }

    if (open > 0)
    {
        generateParenthesisHelper(open - 1, close, current + "(", result);
    }

    if (close > open)
    {
        generateParenthesisHelper(open, close - 1, current + ")", result);
    }
}

// Function to generate all combinations of well-formed parentheses
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generateParenthesisHelper(n, n, "", result);
    return result;
}

int main()
{
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> parentheses = generateParenthesis(n);

    cout << "All combinations of well-formed parentheses:" << endl;
    for (const string &p : parentheses)
    {
        cout << p << endl;
    }

    return 0;
}

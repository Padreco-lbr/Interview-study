// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

// For example,

// A=[1, 3, -1]

// f(1, 1) = f(2, 2) = f(3, 3) = 0
// f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
// f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
// f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

// So, we return 5.

int Solution::maxArr(vector<int> &A) {
    int maxSum, maxSub;
    vector<int> temp(A.size());
    
    // Sum of element and position
    for (int i = 0; i < A.size(); i++) temp[i] = A[i] + i;
    auto result = minmax_element(temp.begin(), temp.end());
    maxSum = abs(
        temp[result.first - temp.begin()]
        - temp[result.second - temp.begin()]
    );
    
    // Subtraction of element and position
    for (int i = 0; i < A.size(); i++) temp[i] = A[i] - i;
    result = minmax_element(temp.begin(), temp.end());
    maxSub = abs(
        temp[result.first - temp.begin()]
        - temp[result.second - temp.begin()]
    );
    
    return max(maxSum, maxSub);
}
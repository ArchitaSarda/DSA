int solution(string s, string t) {
    int count=0;
    // Iterate through each digit in s
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            char removedDigit = s[i];  // Store the digit to be removed
            s.erase(i, 1);  // Remove the digit from s

            // Compare s with t
            if (s < t) {
                count++;
            }

            s.insert(i, 1, removedDigit);  // Restore the removed digit
        }
    }

    // Iterate through each digit in t
    for (int i = 0; i < t.length(); i++) {
        if (isdigit(t[i])) {
            char removedDigit = t[i];  // Store the digit to be removed
            t.erase(i, 1);  // Remove the digit from t

            // Compare s with t
            if (s < t) {
                count++;
            }

            t.insert(i, 1, removedDigit);  // Restore the removed digit
        }
    }
    return count;
}



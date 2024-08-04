// example: ()()
//          ()(())
//          ()(()
//          ())()
// 1. 连续几对括号都有效
// 2. 有效括号被左括号隔开
// 3. 有效括号被右括号隔开
int longestValidParentheses(char* s) {
    int s_len = strlen(s);
    int max_len = 0;
    int left = 0, right = 0;
    int i;

    if (s_len <= 1) {
        return 0;
    }

    // 情形1 + 情形3
    for (i = 0; i < s_len; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left < right) {
            left = 0;
            right = 0;
        } else if (left == right) {
            if (right * 2 > max_len) {
                max_len = right * 2;
            }
        }
    }

    // 情形1 + 情形2
    left = 0; right = 0;
    for (i = s_len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left > right) {
            left = 0;
            right = 0;
        } else if (left == right) {
            if (left * 2 > max_len) {
                max_len = left * 2;
            }
        }
    }

    return max_len;
}
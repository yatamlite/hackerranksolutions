int myAtoi(char* str) {
    if (*str == NULL) {
        return 0;
    }
    
    int sign =1;
    int res = 0, i=0;
    
    //ignore any whitespaces in the beginning
    while (str[i] == ' ') {
        i++;
    }
    /*
     * 1. negative sign, increment i
     * 2. positive sign, increment i
     * 3. no sign in string, do not increment i
     */
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        sign = 1;
        i++;
    } else {
        sign = 1;
    }
    /*
     * Make sure the character is between 0-9
     * Ignore any non numeric characters that come after the number.
     * Ex:  -123asd = -123
     *      -a = 0
     */
    while (str[i] >= '0' && str[i] <= '9') {
        /*
         * INT_MAX = 2147483647 (defined in limits.h)
         * if res = 2147483647/10 then str[i](next char) can only be 0-7,
         * anything over that the value of whole string is INT_MAX.
         */
        if ((res > INT_MAX/10) || ((res == INT_MAX/10) && (str[i]-'0' > 7))) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        res = 10*res + str[i] - '0';
        i++;
    }
    return sign*res;
}

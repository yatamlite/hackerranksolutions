int myAtoi(char* str) {
    if (*str == NULL) {
        return 0;
    }
    
    int sign =1;
    int res = 0, i=0;
    
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        sign = 1;
        i++;
    } else {
        sign = 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
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

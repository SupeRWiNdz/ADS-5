// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char c) {
    if (c == '(') return 0;
    if (c == ')') return 1;
    if ((c == '+') || (c == '-')) return 2;
    if ((c == '*') || (c == '/')) return 3;
}

const bool isOperation(char c) {
    if (c == '-') return 1;
    if (c == '+') return 1;
    if (c == '/') return 1;
    if (c == '*') return 1;
    return 0;
}

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string output = "";
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] >= '0' && inf[i] <= '9') {
            output += inf[i];
            output += " ";
        } else if (inf[i] == '(') {
            stack1.push(inf[i]);
        } else if (isOperation(inf[i])) {
            while (stack1.isEmpty() == 0 &&
                getPrior(inf[i]) <= getPrior(stack1.getTop())) {
                output += stack1.getTop();
                output += " ";
                stack1.pop();
            }
            stack1.push(inf[i]);
        } else if (inf[i] == ')') {
            while (stack1.isEmpty() == 0 && stack1.getTop() != '(') {
                output += stack1.getTop();
                output += " ";
                stack1.pop();
            }
            stack1.pop();
        }
    }
    while (stack1.isEmpty() == 0) {
        output += stack1.getTop();
        output += " ";
        stack1.pop();
    }
    return output;
}
int eval(std::string post) {
    TStack<int, 100> stack2;
    for (int i = 0; i < post.length(); i++) {
        if (post[i] == ' ') {
            continue;
        }
        if (post[i] >= '0' && post[i] <= '9') {
            stack2.push(post[i] - '0');
        } else if (isOperation(post[i])) {
            int temp1 = stack2.getTop();
            stack2.pop();
            int temp2 = stack2.getTop();
            stack2.pop();
            if (post[i] == '+')
                stack2.push(temp2 + temp1);
            if (post[i] == '-')
                stack2.push(temp2 - temp1);
            if (post[i] == '*')
                stack2.push(temp2 * temp1);
            if (post[i] == '/')
                stack2.push(temp2 / temp1);
        }
    }
    return stack2.getTop();
}

from collections import deque

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = deque()
        x = 0
        for c in s:
            if c == ')' and x == 0:
                continue
            if c == '(':
                x += 1
            elif c == ')':
                x -= 1
            stk.append(c)
        
        ans = []
        x = 0
        while stk:
            c = stk.pop()
            if c == '(' and x == 0:
                continue
            if c == ')':
                x += 1
            elif c == '(':
                x -= 1
            ans.append(c)
        
        return ''.join(reversed(ans))

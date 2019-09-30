import sys
sys.setrecursionlimit(100000)

class Mod1000000007():

    def __init__(self, n):
        self.n = n%1000000007

    def plus(self, m):
        self.n = (self.n + m)%1000000007
        return self

    def minus(self, m):
        self.n = (self.n - m)%1000000007
        return self

    def times(self, m):
        self.n = ((self.n)*(m%1000000007))%1000000007
        return self

    def frac(self, m):
        l = [1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1]
        ans = 1
        pow = m%1000000007
        for i in range(len(l)):
            if l[i] == 1:
                ans = (ans*pow)%1000000007
            if i != len(l)-1:
                pow = (pow**2)%1000000007
        return self.times(ans)
    
(n, k) = (int(input()), int(input()))
ans = Mod1000000007(1)
for j in range(k):
    ans.times(n+j).frac(j+1)

print(ans.n)
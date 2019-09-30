N = int(input())
S = input()
D = {'A':4, 'B':3, 'C':2, 'D':1, 'F':0}
ans = 0
for c in S:
    ans += D[c]
print(ans / N)
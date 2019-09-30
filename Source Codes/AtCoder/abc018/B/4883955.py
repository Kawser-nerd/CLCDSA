s = input()
n = int(input())
lr = [[int(i)-1 for i in input().split()] for i in range(n)]

for l,r in lr:
    s = s[:l] + s[l:r+1][::-1] + s[r+1:]

print(s)
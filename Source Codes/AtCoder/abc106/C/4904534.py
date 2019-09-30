import sys

s=input()
k=int(input())

for i in range(k-1):
    if int(s[i])!=1:
        print(int(s[i]))
        sys.exit()

print(s[k-1])
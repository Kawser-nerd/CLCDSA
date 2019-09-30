n = int(input())
s = input()
t = input()
l = len(s)+len(t)
for i in range(n,0,-1):
    if t[:i] in s:
        print(l-i)
        break
else:
    print(l)
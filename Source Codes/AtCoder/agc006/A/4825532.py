n = int(input())
s = input()
t = input()

if s == t:
    print(n)
    exit()

for i in range(1, n):
    if s[-i:] == t[:i]:
        print(n*2-i)
        exit()
else:
    print(n*2)
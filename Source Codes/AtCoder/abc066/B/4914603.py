s = input()
n = len(s)
s = list(s)
s.pop(len(s)-1)
s.pop(len(s)-2)
for i in range(2,n+1,2):
    if s[:(n-i)//2]==s[(n-i)//2:]:
        print(n-i)
        exit()
    s.pop(n-i-1)
    s.pop(n-i-2)
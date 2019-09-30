s = input()
n = int(input())
if len(s) >= n:
    a = [s[i:i+n] for i in range(len(s) - n+1)]
    ans = len(set(a))    
else:
    ans = 0
print(ans)
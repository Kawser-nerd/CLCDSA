N = input()
N =int(N)
s = input()
t = input()
y = 0
for i in range(N):
    q = s[-(i+1):]
    r = t[:i+1]
    if q == r :
        x = q
        y =i+1
print(N*2-y)
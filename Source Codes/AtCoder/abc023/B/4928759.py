N = int(input())
S_in = input()

cnt = (N-1)//2

S = 'b'
for i in range(1, cnt+1):
    if i%3==1:
        S = 'a' + S + 'c'
    elif i%3==2:
        S = 'c' + S + 'a'
    else:
        S = 'b' + S + 'b'
        
if S == S_in:
    print(cnt)
else:
    print(-1)
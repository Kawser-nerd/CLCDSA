#23?
n = int(input())
s = input()

if n%2==0 or len(s)%2==0:
    print(-1)
else:
    T = (n-1)//2
    temp = 'b'
    for i in range(1,T+1):
        if i%3==1:
            temp = 'a'+temp+'c'
        elif i%3==2:
            temp = 'c'+temp+'a'
        else:
            temp = 'b'+temp+'b'
    if s==temp:
        print(T)
    else:
        print(-1)
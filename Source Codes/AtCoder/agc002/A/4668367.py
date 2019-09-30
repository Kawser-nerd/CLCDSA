a,b=map(int,input().split())
if 0<a<=b:
    print('Positive')
elif a<=b<0:
    if (b-a+1)%2==0:
        print('Positive')
    else:
        print('Negative')
else:
    print('Zero')
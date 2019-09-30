N,A,B = map(int,input().split())
newN = N - N//(A+B) * (A+B)
if newN == 0:
    print('Bug')
elif A >= newN:print('Ant')
else:print('Bug')
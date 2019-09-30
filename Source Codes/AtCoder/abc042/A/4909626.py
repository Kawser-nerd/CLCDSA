a,b,c = map(int,input().split())
numberlist=[a,b,c]
numberlist.sort()
if (numberlist[0]==5 and numberlist[1]==5 and numberlist[2]==7):
    print('YES')
else :
    print('NO')
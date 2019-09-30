import sys
sys.setrecursionlimit(1000000)
#def input():
#    return sys.stdin.readline()[:-1]

'''
n=int(input())
for i in range(n):
    a[i]=int(input())
    a[i],b[i]=map(int,input().split())
a=[int(x) for x in input().split()]
n,m=map(int,input.split())
from operator import itemgetter
a = [(1, "c", 1), (1, "b", 3), (2, "a", 0), (1, "a", 2)]
print(sorted(a))  # 0 ???????????????????? 1 ??????????
print(sorted(a, key=itemgetter(0)))  # 0 ???????????
print(sorted(a, key=itemgetter(0, 2)))  # 0 ??? 2 ?????????
print(sorted(a, key=lambda x: x[0] * x[2]))  # 0 ????? * 2 ?????????
print(sorted(a, reverse=True))  # ??????
a.sort()  # ????????sorted() ?????
try: # ??????? list index out of range
    for i in range():
        k=b[i]
except IndexError as e:
    print(i)
'''

test_data1 = '''\
A??C
'''

test_data2 = '''\
ACACAC
'''

test_data3 = '''\
????C?????B??????A???????
'''

test_data4 = '''\
?AC?AC
'''
td_num=3

def GetTestData(index):
    if index==1:
        return test_data1
    if index==2:
        return test_data2
    if index==3:
        return test_data3
    if index==4:
        return test_data4
    
if False:
    with open("../test.txt", mode='w') as f:
        f.write(GetTestData(td_num))
    with open("../test.txt") as f:
        # Start Input code ---------------------------------------
        s=f.readline()
        # End Input code ---------------------------------------
else:
    # Start Input code ---------------------------------------
    s=input()
    # End Input code ---------------------------------------
n=len(s)
dc=dict()
dc['A']=0
dc['B']=1
dc['C']=2
dc['?']=3
dp=[[0 for i in range(4)] for j in range(n+1)]
dp[0][0]=1
mo=10**9+7
for i in range(n):
    for t in range(4):
        ch=s[i]
        if dc[ch]==t-1 or dc[ch]==3:
            m=1
        else:
            m=0
        if t!=0:
            dp[i+1][t]+=(dp[i][t-1]*m)%mo
        dp[i+1][t]+=(dp[i][t]*max(int(dc[ch]/3)*3,1))%mo
#print(dp)
ans=dp[n][3]

#mo=2291979612924+1
#print(ans,'n,s=',n,s,'lc(a,w)=',lc_a,lc_w,'rc(c,w)=',rc_c,rc_w)
    #print('i,ans',i,ans)
#print(ans,'n,s=',n,s,'lc(a,w)=',lc_a,lc_w,'rc(c,w)=',rc_c,rc_w)
print(ans%mo)
#ans=count(0)+2^(count(n)-1)
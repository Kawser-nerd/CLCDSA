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
lc_a=[0]*n
lc_c=[0]*n
lc_w=[0]*n
rc_a=[0]*n
rc_c=[0]*n
rc_w=[0]*n
rc_a0=s.count('A')
rc_c0=s.count('C')
rc_w0=s.count('?')
c_a=0
c_c=0
c_w=0
for i in range(n-1):
    ch=s[i]
    if ch=='A':
        c_a+=1
    if ch=='C':
        c_c+=1        
    if ch=='?':
        c_w+=1
    lc_a[i+1]=c_a
    #lc_c[i+1]=c_c
    lc_w[i+1]=c_w
    #rc_a[i+1]=rc_a[0]-c_a
    rc_c[i]=rc_c0-c_c
    rc_w[i]=rc_w0-c_w
      
ans=0
mo=10**9+7
#mo=2291979612924+1
#print(ans,'n,s=',n,s,'lc(a,w)=',lc_a,lc_w,'rc(c,w)=',rc_c,rc_w)
for i in range(1,n-1):
    ch=s[i]
    if ch=='B' or ch=='?':
        ans+=(lc_a[i]*pow(3,lc_w[i],mo)+pow(3,max(0,lc_w[i]-1),mo)*lc_w[i])*(rc_c[i]*pow(3,rc_w[i],mo)+pow(3,max(0,rc_w[i]-1),mo)*rc_w[i])%mo
    #print('i,ans',i,ans)
#print(ans,'n,s=',n,s,'lc(a,w)=',lc_a,lc_w,'rc(c,w)=',rc_c,rc_w)
print(ans%mo)
#ans=count(0)+2^(count(n)-1)
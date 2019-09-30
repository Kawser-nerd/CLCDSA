
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

top=2505

for c in range(int(input())):
    # find all numbers that appear an odd number of times
    n=int(input())
    count=[0]*top
    for _ in range(2*n-1):
        for i in map(int,input().split()):
            count[i]+=1
    ans=[]
    for i in range(top):
        if count[i]%2: ans.append(i)
    print("Case #%s: %s"%(c+1," ".join(map(str,ans))))

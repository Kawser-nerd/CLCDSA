
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

for case in range(int(input())):
    n=int(input())
    if n==0:
        print("Case #%s: INSOMNIA"%(case+1))
    else:
        left=[1]*10
        count=10
        for i in range(1,10000000):
            for ch in map(int,str(n*i)):
                if left[ch]:
                    left[ch]=0
                    count-=1
            if count==0:
                print("Case #%s: %s"%(case+1,n*i))
                break

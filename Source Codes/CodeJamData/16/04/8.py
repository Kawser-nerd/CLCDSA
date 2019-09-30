
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

for case in range(int(input())):
    k,c,s=map(int,input().split())
    # c = number of digit values that can be checked at once
    # k = number of digit values in total
    if c*s<k: print("Case #%s: IMPOSSIBLE"%(case+1))
    else:
        # put stuff
        check=[]
        num=0
        carry=0
        for i in range(k):
            num*=k
            num+=i
            carry+=1
            if carry==c:
                check.append(num+1)
                carry=0
                num=0
        if carry: check.append(num+1)
        print("Case #%s: %s"%(case+1," ".join(map(str,check))))

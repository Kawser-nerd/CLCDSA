
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

"""
import itertools
def sol1(s):
    s=s.strip()+"+"
    count=0
    for i in range(len(s)-1):
        if s[i]!=s[i+1]: count+=1
    return count

def sol2(s):
    n=len(s.strip())
    good="+"*(n)
    used=set([s.strip()])
    l1=set([s.strip()])
    step=0
    while good not in used:
        l2=set()
        for i in l1:
            for j in range(1,n+1):
                # flip
                u="".join(map(lambda ch: {"+":"-","-":"+"}[ch],i[:j]))+i[j:]
                if u not in used:
                    used.add(u)
                    l2.add(u)
        l1=l2
        step+=1
    return step

# test
for test in map(lambda s:"".join(s),itertools.product('+-',repeat=10)):
    if sol1(test)!=sol2(test):
        print(test,sol1(test),sol2(test))
"""

for case in range(int(input())):
    s=input().strip()+"+"
    count=0
    for i in range(len(s)-1):
        if s[i]!=s[i+1]: count+=1
    print("Case #%s: %s"%(case+1,count))

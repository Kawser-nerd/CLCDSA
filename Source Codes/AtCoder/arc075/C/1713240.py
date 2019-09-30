class BIT(object):

    def __init__(self, n):
        self.n=n
        self.lst=[0]*(n+1)

    def put(self, i):
        while(i<=self.n):
            self.lst[i]+=1
            i+=(i&-i)

    def get(self, i):
        ret=0
        while(i!=0):
            ret+=self.lst[i]
            i-=(i&-i)
        return ret

if __name__ == '__main__':
    ipt=input().split(' ')
    n=int(ipt[0])
    k=int(ipt[1])
    a=[(0,1)]
    for i in range(n):
        a.append((a[-1][0]+int(input())-k, i+2))
    a.sort()
    bit=BIT(n+1)
    ret=0
    for e in a:
        ret+=bit.get(e[1])
        bit.put(e[1])
    print(ret)
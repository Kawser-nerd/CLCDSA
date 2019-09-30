N,K=map(int,input().split())
D=list(input().split())

for i in range(N,100000):
        ans=True
        for j in str(i):
                if(str(j) in D):
                        ans=False
                        break
        if(ans):
                print(i)
                exit()
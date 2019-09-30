n,a,b=map(int,input().split())
print(sum([i for i in range(1,n+1) if a<=eval('+'.join(list(str(i))))<=b]))
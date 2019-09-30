#098
a,b= map(int,input().split())
print(sum([i for i in range(b-a)])-a)
abc = list(map(int,input().split()))
k=int(input())
sum_abc=sum(abc)-max(abc)+max(abc)*(2**k)
print(sum_abc)
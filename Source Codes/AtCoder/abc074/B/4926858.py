n = int(input())
k = int(input())
x = list(map(int, input().split()))
x = [min(i,abs(k-i))*2 for i in x]
print(sum(x))
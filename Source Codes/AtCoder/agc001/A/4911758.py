n = int(input())
kushi = list(map(int, input().split()))
kushi.sort()
setkushi = [min(kushi[2*i], kushi[2*i+1]) for i in range(n)]
print(sum(setkushi))
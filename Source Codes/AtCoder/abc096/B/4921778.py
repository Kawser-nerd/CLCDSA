ABC = list(map(int, input().split()))
K = int(input())
print(max(ABC) * (2**K) + sum(ABC) - max(ABC))
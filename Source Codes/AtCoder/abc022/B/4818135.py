n = int(input())
flower = [int(input()) for i in range(n)]
print(len(flower) - len(set(flower)))
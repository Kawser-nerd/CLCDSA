N = int(input())
S = [input() for i in range(N)]
S.sort(key=lambda x:x[::-1])
print(*S, sep='\n')
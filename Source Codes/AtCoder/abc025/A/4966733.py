S = input('')
N = int(input())
a = N % 5
b = int(N - 1) // 5  
print(S[b] + S[a-1])
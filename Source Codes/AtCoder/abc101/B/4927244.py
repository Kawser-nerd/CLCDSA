N = int(input())
N_s = list(str(N))
N_s = list(map(int, N_s))
print('Yes' if N % sum(N_s) == 0 else 'No')
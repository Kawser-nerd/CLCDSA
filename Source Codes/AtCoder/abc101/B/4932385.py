N = input()

n = int(N)
sn = sum(list(map(int, list(N))))

print('Yes' if n % sn == 0 else 'No')
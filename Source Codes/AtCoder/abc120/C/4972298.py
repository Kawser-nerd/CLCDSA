S = input()
N = len(S)
num_zero = 0
for c in S:
    if c=='0':
        num_zero += 1
print(min(num_zero, N-num_zero)*2)
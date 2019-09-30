N = int(input())
a = list(map(int, input().split()))
a.append(0)

def sum_alithmetic_progression(a, d, n):
    return n * (2 * a + (n - 1) * d) // 2

seq_length = 1
sum_v = 0
for i in range(N):
    if a[i] < a[i+1]:
        seq_length += 1
    else:
        sum_v += sum_alithmetic_progression(1, 1, seq_length)
        seq_length = 1
print(sum_v)
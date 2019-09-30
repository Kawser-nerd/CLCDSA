N = int(input())
c = [int(input()) for i in range(N)]
max_seq = 0
temp_seq = 1
first_seq = 0

for i in range(N-1):
    if c[i] == c[i+1]:
        temp_seq += 1
    else:
        if first_seq == 0:
            first_seq = temp_seq
        max_seq = max(max_seq, temp_seq)
        temp_seq = 1

if c[0] == c[-1] and first_seq > 0:
    temp_seq += first_seq

max_seq = max(max_seq, temp_seq)

if max_seq == N:
    print(-1)
else:
    print((max_seq+1) // 2)
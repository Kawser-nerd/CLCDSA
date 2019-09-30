def calculate_num_of_divisor(N):
    yakusuu = []
    for i in range(1, N+1):
        if N % i == 0:
            yakusuu.append(i)
    return len(yakusuu)

N = int(input())
count = []
for i in range(N+1):
    if i % 2 == 1 and calculate_num_of_divisor(i) == 8:
        count.append(i)
print(len(count))
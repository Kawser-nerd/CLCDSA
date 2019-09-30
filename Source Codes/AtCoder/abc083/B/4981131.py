inputs = input().split()
N, A, B = list(map(int, inputs))
nums = []

for i in range(N+1):
    all = 0
    for j in range(len(str(i))):
        all += int(str(i)[j])
    if A <= all <= B:
        nums.append(i)

print(sum(nums))
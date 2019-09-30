N  = int(input())

already = set()
count = 0
for n in range(N):
    A = input()
    if A in already:
        count += 1
    else:
        already.add(A)
print(count)
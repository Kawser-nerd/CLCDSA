N = int(input())

B = [int(input()) for _ in range(N-1)]

staffs = {}
for i, b in enumerate(B):
    staffs.setdefault(b, set()).add(i+2)

def salary(x):
    if x not in staffs:
        return 1
    salaries = [salary(y) for y in staffs[x]]
    return max(salaries)+min(salaries) + 1

print(salary(1))
N = int(input())

# [6, 28, 496, 8128, 33550336, 8589869056, 137438691328]

def f(n):
    s = set()
    for i in range(1, int(n**(1/2))+1):
        if n%i == 0:
            s.add(n//i)
            s.add(i)
    return s

sum_num = sum(f(N))-N
if sum_num < N:
    print("Deficient")
elif sum_num > N:
    print("Abundant")
else:
    print("Perfect")
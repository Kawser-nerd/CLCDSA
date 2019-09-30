from math import sqrt

n = int(input())

nums = set()

d_nums = set()

for i in range(1, int(sqrt(n)) + 1):

    if n % i == 0 and i != n:

        nums.add(i)

for num in nums:

    p, q = divmod(n, num)

    if q == 0 and p != n:

        d_nums.add(p)

m_nums = nums | d_nums

t = sum(m_nums)

if t == n:

    print('Perfect')

elif t > n:

    print('Abundant')

else:

    print('Deficient')
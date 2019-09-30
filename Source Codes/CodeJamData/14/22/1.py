"""
001
010
011
100
101
110
...


how many pairs of numbers will AND to those numbers?


  well, every 1 must be set in both.
  every 0 has 0 choices: 00, 01, or 10

  so it's 3^(num 0s)
"""

n = int(input())

for caseno in range(1,1+n):
  a, b, c = [int(x) for x in input().split()]

  def total(i, j, k):
    # i, j, and k are the number of bits that can be either 0 or 1

    # We're counting the number of choices for a and b that wind up valid c

    total = 1

    for q in range(31,-1,-1):
      abit = (0 if q == i else (1 if (a&(1<<q)) else 0))
      bbit = (0 if q == j else (1 if (b&(1<<q)) else 0))
      cbit = (0 if q == k else (1 if (c&(1<<q)) else 0))

      if q < i and q < j and q < k:
        total *= 4

      if q >= i and q < j and q < k:
        # No matter which b you pick, it's fine.
        total *= 2
      if q < i and q >= j and q < k:
        # Same with a
        total *= 2
      if q < i and q < j and q >= k:
        # If c is 1, only 1 choice. otherwise, 3
        if not cbit:
          total *= 3

      if q >= i and q >= j and q < k:
        pass
      if q >= i and q < j and q >= k:
        if cbit and abit:
          total *= 1
        if cbit and not abit:
          total *= 0
        if not cbit and abit:
          total *= 1
        if not cbit and not abit:
          total *= 2
      if q < i and q >= j and q >= k:
        if cbit and bbit:
          total *= 1
        if cbit and not bbit:
          total *= 0
        if not cbit and bbit:
          total *= 1
        if not cbit and not bbit:
          total *= 2

      if q >= i and q >= j and q >= k:
        if abit & bbit != cbit:
          total *= 0
    return total

  answer=0
  for i in range(31,-1,-1):
    for j in range(31,-1,-1):
      for k in range(31,-1,-1):
        if (a&(1<<i)) and (b&(1<<j)) and (c&(1<<k)):
          answer += total(i,j,k)
  print("Case #"+str(caseno)+": "+str(answer))

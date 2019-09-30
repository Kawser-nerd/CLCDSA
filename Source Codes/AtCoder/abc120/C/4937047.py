S = str(input())

s = S

zero = s.count('0')
one = s.count('1')

zero_one_diff = max(zero, one) - min(zero, one)
print(len(s) - zero_one_diff)
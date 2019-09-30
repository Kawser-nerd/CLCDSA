s = input()

zero = s.count('0')
one = s.count('1')

print(2 * min(zero, one))
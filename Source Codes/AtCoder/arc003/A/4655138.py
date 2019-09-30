N = int(input())
r = input()

numA = r.count('A')
numB = r.count('B')
numC = r.count('C')
numD = r.count('D')

print((4*numA+3*numB+2*numC+numD)/N)
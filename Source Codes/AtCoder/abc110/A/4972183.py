N = [int(i) for i in input().split()]
N.sort()
print(int(str(N[2]) + str(N[1])) + N[0])
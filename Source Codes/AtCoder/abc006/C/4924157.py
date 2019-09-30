import sys
N,M = map(int, input().split())

for baby in range(N+1):
    elder = M -2*N -2*baby
    adult = N - elder - baby
    if elder<0 or adult<0:
        continue
    print(adult, elder, baby)
    sys.exit()

print("{} {} {}".format(-1, -1, -1))
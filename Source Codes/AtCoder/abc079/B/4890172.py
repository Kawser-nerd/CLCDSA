N = int(input())

luca = [2,1]

while len(luca) <= N:
    luca.append(luca[-2] + luca[-1])

print(luca[N])
N = int(input())

for t in range(10**5):
    if t*(t+1)/2 >= N:
        print(t)
        break
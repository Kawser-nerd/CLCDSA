N = int(input())
A = list(map(int, input().split()))

monsters = A[:]
while True:
    a_min = min(monsters)
    monsters = [m % a_min for m in monsters if m % a_min != 0]
    if len(monsters) == 0:
        print(a_min)
        break
    else:
        monsters.append(a_min)
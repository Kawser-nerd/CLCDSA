NA, NB = map(int, input().split(" "))
A, B = [set(map(int, input().split(" "))) for _ in range(2)]

print(len(A&B)/len(A|B))
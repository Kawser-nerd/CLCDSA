X = int(input())
A = int(input())
B = int(input())

tmp = X-A
tmp = tmp - B*(tmp//B)
print(tmp)
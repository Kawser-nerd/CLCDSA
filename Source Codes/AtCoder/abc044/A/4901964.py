n = int(input())
k = int(input())
x = int(input())
y = int(input())

en = 0
for i  in range(n):
    if i + 1  < k +1:
        en += x
    else:
        en += y

print(en)
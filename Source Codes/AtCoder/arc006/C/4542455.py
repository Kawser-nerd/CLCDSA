n = int(input())
w = [int(input()) for _ in range(n)]
result = []
number = []

for i in range(n):
    if i not in number:
        list = [w[i]]
        number.append(i)
        for j in range(i,n):
            if w[i] >= w[j] and j not in number:
                list.append(w[j])
                number.append(j)
                w[i] = w[j]
        result.append(list)

print(len(result))
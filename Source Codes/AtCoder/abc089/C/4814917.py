N = int(input())
march = 'MARCH'
l = [0] * len(march)
for i in range(N):
    S = input()
    for j in range(len(march)):
        if S[0] == march[j]:
            l[j] += 1

# print(l)
tmp = []
lenl = len(l)
for i in range(lenl):
    for j in range(i + 1, lenl):
        for k in range(j + 1, lenl):
           tmp.append(l[i]*l[j]*l[k])
# print('tmp',tmp)
print(sum(tmp))
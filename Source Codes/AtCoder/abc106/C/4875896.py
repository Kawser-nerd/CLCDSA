S = str(input())
k = int(input())
for i in range(k):
    if S[i] != "1":
        print(S[i])
        exit()
print("1")
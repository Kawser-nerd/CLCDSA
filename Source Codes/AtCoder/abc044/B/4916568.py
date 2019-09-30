import collections
S = list(input())
count = collections.Counter(S).most_common()

for i in range(len(count)):
    if (int(count[i][1]) % 2 != 0):
        print("No")
        exit()
print("Yes")
n = int(input())
w = input().split()
ans = []
for i in w:
    ans.append(i.lower().translate(str.maketrans("bcdwtjfqlvsxpmhkngzr","11223344556677889900","aiueoy,.")))
print(" ".join([i for i in ans if i != ""]))
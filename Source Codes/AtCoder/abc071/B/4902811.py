S = input().rstrip()
element = [0]*26
for i in range(len(S)):
    s = ord(S[i]) - ord("a")
    element[s] += 1
zero = element.count(0)
print("None" if zero == 0 else chr(ord("a") + element.index(0)))
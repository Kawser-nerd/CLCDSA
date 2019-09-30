s = input()
arr = s.split("+")

cnt = 0
for x in arr:
    if "0" not in x:
        cnt+=1
print(cnt)
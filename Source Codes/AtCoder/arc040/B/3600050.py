a,b= map(int,input().split(" "))
ar = list(input())
i = 0
count = 0
while ar.count(".") != 0:
    if i + b >= a:
        c = a
    else:
        c = i + b
    if ar[i] == ".":
        for j in range(i,c):
            ar[j] = "o"
        count += 1
    else:
        if ar[i:c].count(".") == ar.count("."):
            for k in range(i,c):
                ar[k] = "o"
            count += 1
        else:
            i += 1
            count += 1
print(count)
N = input()
lst = list(map(int, input().split()))
maxval = max(lst)
lst.remove(maxval)
total = sum(lst)

if total > maxval:
    print("Yes")
else:
    print("No")
n = int(input())
done = set()
start = input()
done.add(start)
status = True
for i in range(n-1):
    x = input()
    if x in done:
        status = False
    if x[0] != start[-1]:
        status = False
    done.add(x)
    start = x
if status:
    print("Yes")
else:
    print("No")
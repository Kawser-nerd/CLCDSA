N = int(input())
depth = len(bin(N))-2
def func():
    x = 1
    for d in range(80):
        if d % 2 == depth % 2:
            x = 2*x
        elif d % 2 != depth % 2:
            x = 2*x + 1
        if x > N:
            break
    return d
d = func()
ans = ["Aoki","Takahashi"]
index = d % 2
print(ans[index])
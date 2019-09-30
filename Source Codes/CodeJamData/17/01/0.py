def run_test():
    s, k = input().split()
    k = int(k)
    s = [c == '+' for c in s]
    flips = 0
    #print(s)
    for i in range(len(s) - k + 1):
        if not s[i]:
            #print("flip at " + str(i))
            flips += 1
            for j in range(i, i + k):
                s[j] = not s[j]
            #print(s)
    return flips if all(s) else "IMPOSSIBLE"

for i in range(1, int(input()) + 1):
    print("Case #{}: {}".format(i, run_test()))

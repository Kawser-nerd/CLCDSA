import copy

def possible(Workers, Machines, can):
    if Workers == []:
        return True
    for worker in Workers:
        result = False
        for machine in Machines:
            if can[worker][machine] == "1":
                Workers.remove(worker)
                Machines.remove(machine)
                r = possible(Workers, Machines, can)
                Workers.add(worker)
                Machines.add(machine)
                if r == False:
                    return False
                else:
                    result = True
        if result == False:
            return False
    return True

def solve():
    n = int(input())
    can = [list(input()) for i in range(n)]
    ans = 100000
    can_saved = copy.deepcopy(can)
    for mask in range(2 ** (n * n)):
        can = copy.deepcopy(can_saved)
        corr = True
        s = 0
        for i in range(n):
            for j in range(n):
                if (mask >> (i * n + j)) & 1 == 1:
                    if can[i][j] == "0":
                        can[i][j] = "1"
                        s += 1
                    else:
                        corr = False
                        break
            if corr == False:
                break
        if corr and s < ans and possible({i for i in range(n)}, {i for i in range(n)}, can):
            ans = s
    return ans

for i in range(1, int(input()) + 1):
    print("Case #", i, ": ", solve(), sep="")


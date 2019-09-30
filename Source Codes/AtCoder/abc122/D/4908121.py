MOD = 10**9+7

N = int(input())

countA = 4
countG = 4
countAG = 1
countGA = 1
countAC = 1
countAGX = 0
countAXG = 0
countAT = 1
ans = 16
nextnums = [0 for _ in range(7)]
for i in range(N-2):
    nextans = ans*4 - countAG - countGA - countAC - countAXG - countAGX
    nextA = ans
    nextG = ans - countAC
    nextAG = countA
    nextGA = countG
    nextAC = countA - countGA
    nextAGX = 2 * countAG
    nextAXG = countAT
    nextAT = countA

    ans = nextans % MOD
    countA = nextA % MOD
    countAC = nextAC % MOD
    countAG = nextAG % MOD
    countAGX = nextAGX % MOD
    countAT = nextAT % MOD
    countAXG = nextAXG % MOD
    countG = nextG % MOD
    countGA = nextGA % MOD
print(ans)
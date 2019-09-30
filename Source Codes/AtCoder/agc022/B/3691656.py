N = int(input())
N1 = N
candi22 = [20 + 6*i for i in range(4997)]
candi24 = [4 + 6*i for i in range(5000)]
candi3 =  [15 + 6*i for i in range(4998)]
candi6 =  [6 + 6*i for i in range(5000)]
if N == 3:
    print(2, 5, 63)
elif N == 4:
    print(2, 5, 20, 63)
elif N >= 15000:
    ans = [2, 8, 14, 3, 9]
    ans += candi22 + candi24 + candi3 + candi6[:N-15000]
    print(*ans)
else:
    ans = [2, 8, 14, 3, 9]
    N -= 5
    c22 = min(4995, N//3*3)
    N -= c22
    c24 = min(4998, N//3*3)
    N -= c24
    c3 = min(4998, N//2*2)
    N -= c3
    c6 = N
    ans += candi22[:c22] + candi24[:c24] + candi3[:c3] + candi6[:c6]
    print(*ans)
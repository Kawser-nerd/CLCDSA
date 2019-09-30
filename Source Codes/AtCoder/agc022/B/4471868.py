N = int(input())
if N < 5002:
    if N % 2  == 0:
        sans = [6 * i  + 3 for i in range(N-2)]
        ans = sans + [2,4]
    if N % 2 == 1:
        sans = [6 * i  + 3 for i in range(N-3)]
        ans = sans + [2,4,6]
    if N == 3:
        ans = [2,3,25]
else:
    sans = [6 * i  + 3 for i in range(5000)]
    nis = [2 * i + 2 for i in range(N - 5000 )]
    if (len(nis) * (nis[0] + nis[-1]) //2) % 3 == 1:
        nis[-1] += 2
    elif    (len(nis) * (nis[0] + nis[-1]) //2) % 3 == 2:
        nis[-1] += 2
        nis[-2] += 2
    ans = sans + nis
ans = map(str,ans)
print(" ".join(ans))
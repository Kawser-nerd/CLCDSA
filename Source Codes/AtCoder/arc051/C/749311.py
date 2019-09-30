def solve(A,loop):
    result = 1
    temp = A
    binloop = reversed(str(bin(loop))[2:])
    for i in binloop:
        if i == "1":
            result = (result * temp) % 1000000007
        temp = temp * temp % 1000000007
    return result

N,A,B = map(int, input().split())
arr = list(map(int, input().split()))
arr_max = max(arr)
arr_min = min(arr)
count = 0

if A == 1:
    arr = sorted(arr)
    for a in arr:
        print(a% 1000000007)
else:
    while count < B and arr_max/arr_min > A:
        count += 1
        arr[arr.index(arr_min)] = arr_min * A
        arr_max = max(arr)
        arr_min = min(arr)


    arr = sorted(arr)
    rest = (B-count)%N
    for i in range(rest):
        arr[i] = arr[i] * A
    arr = sorted(arr)

    loop = int((B-count-rest)/N)
    temp = solve(A,loop)
    for a in arr:
        print(a*temp%1000000007)
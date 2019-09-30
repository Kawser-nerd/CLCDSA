A, B, C = map(int, input().split())
K = int(input())
arr = [A, B, C]
for _ in range(K):
    arr1 = 2 * arr[0] + arr[1] + arr[2]
    arr2 = arr[0] + 2 * arr[1] + arr[2]
    arr3 = arr[0] + arr[1] + 2 * arr[2]
    tmp = [arr1, arr2, arr3]
    idx = tmp.index(max(tmp))
    arr[idx] *= 2
print(sum(arr))
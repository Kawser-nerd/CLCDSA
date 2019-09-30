abc = list(map(int, input().split()))
abc.sort()
print('YES' if [5, 5, 7]==abc else 'NO')
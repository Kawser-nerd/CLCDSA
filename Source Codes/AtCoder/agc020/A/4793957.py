N, A, B = map(int, input().split())
print(["Alice","Borys"][(B-A)%2!=0])
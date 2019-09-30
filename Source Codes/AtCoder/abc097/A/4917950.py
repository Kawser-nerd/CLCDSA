A, B, C, D = map(int, input().split())
print(["Yes", "No"][not(abs(C-A)<=D or (abs(B-A)<=D and abs(C-B)<=D))])
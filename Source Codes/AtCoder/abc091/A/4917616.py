A, B, C = map(int, input().split())
print(["Yes", "No"][not(C <= A + B)])
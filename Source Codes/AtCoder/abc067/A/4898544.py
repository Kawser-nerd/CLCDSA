A, B = map(int, input().split())
print(["Possible", "Impossible"][not(A % 3 == 0 or B % 3 == 0 or (A + B) % 3 == 0)])
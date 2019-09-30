S = input()
A, B, C, D = map(int, input().split())
print(S[:A] + '"' + S[A:B] + '"' + S[B:C] + '"' + S[C:D] + '"' + S[D:])
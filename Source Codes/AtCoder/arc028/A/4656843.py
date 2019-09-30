N, A, B = map(int, input().split())
print("Ant" if N%(A+B) != 0 and N%(A+B) <= A else "Bug")
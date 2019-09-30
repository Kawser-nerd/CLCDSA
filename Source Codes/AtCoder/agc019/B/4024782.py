from collections import defaultdict
A = input()
Alphabet = defaultdict(int)

for i in range(len(A)):
    Alphabet[A[i]] += 1
Total = (len(A) - 1) * len(A) // 2 + 1
for key in Alphabet:
    if Alphabet[key] > 1:
        double = (Alphabet[key] - 1) * Alphabet[key] // 2
        Total -= double
print(Total)
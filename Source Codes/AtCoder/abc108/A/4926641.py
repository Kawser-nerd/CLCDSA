import sys
K = int(input()) #i?????int??????

kumi = list(range(0,K+1))
l_even = [i for i in kumi if i % 2 == 0 and i != 0]
l_kisu = [i for i in kumi if i % 2 != 0]

answer = len(l_even) * len(l_kisu)

print(answer)
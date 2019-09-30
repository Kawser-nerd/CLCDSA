N=int(input())
S=input()

R=S.count("R")
G=S.count("G")
B=S.count("B")

print(R%2+G%2+B%2)
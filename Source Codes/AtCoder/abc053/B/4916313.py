s=input()

print(len(s)-s[::-1].index('Z')-s.index('A'))
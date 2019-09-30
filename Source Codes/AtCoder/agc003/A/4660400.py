S = input()
flagNS = (('N' in S) == ('S' in S))
flagEW = (('E' in S) == ('W' in S))

print("Yes" if flagNS and flagEW else "No")
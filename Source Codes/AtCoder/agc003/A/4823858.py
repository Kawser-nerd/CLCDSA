s = list(set(list(input())))
print("Yes" if s.count('N') == s.count('S') and s.count('E') == s.count('W') else "No")
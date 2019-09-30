s = input()
print("First" if (s[0] == s[-1]) == (len(s) % 2 == 0) else "Second")
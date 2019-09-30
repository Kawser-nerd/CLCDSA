a = str(input())
b = [str(i) for i in a]

c = len(set(b))

print("SAME" if c ==1 else "DIFFERENT")
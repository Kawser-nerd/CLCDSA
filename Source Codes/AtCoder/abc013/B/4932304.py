a = int(input())
b = int(input())
print(abs(a-b) if abs(a-b) < 5 else abs(a+10-b) if a < b else (b+10-a))
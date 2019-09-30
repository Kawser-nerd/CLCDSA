a = int(input())
b = int(input())
print(b-(a%b) if a%b != 0 else 0)
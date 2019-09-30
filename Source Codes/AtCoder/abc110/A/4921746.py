ABC = list(map(int, input().split()))

ABC = sorted(ABC, reverse=True)

print(int(str(ABC[0])+str(ABC[1])) + ABC[2])
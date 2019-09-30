N = int(input())
X = [input() for _ in range(N)]

count = 0
for x in zip(*X):
    count += x.count("x")
    b = ""
    for x_i in x:
        if x_i == "o" and b != "o":
            count += 1 
        b = x_i
print(count)
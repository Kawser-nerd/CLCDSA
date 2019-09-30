A,B = map(int,input().split())

Acount = 1
Bcount = 1

print(40,100)
for j in range(19):
    OUTPUT = ""
    for i in range(100):
        if i%2==0 and j%2==0 and Acount<A:
            Acount += 1
            OUTPUT += "."
        else: OUTPUT += "#"
    print(OUTPUT)
print("".join(["#" for i in range(100)]))

B_OUTPUT = []
for j in range(19):
    OUTPUT = ""
    for i in range(100):
        if i%2==0 and j%2==0 and Bcount<B:
            Bcount += 1
            OUTPUT += "#"
        else: OUTPUT += "."
    B_OUTPUT.append(OUTPUT)
B_OUTPUT.append("".join(["." for i in range(100)]))

for b in B_OUTPUT[::-1]:
    print(b)
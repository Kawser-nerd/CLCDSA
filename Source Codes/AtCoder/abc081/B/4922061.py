N = int(input())
A = input().split()
AA = [int(s) for s in A]

def Even(X):
    counter = 0
    for i in range(len(X)):
        if X[i] % 2 == 0:
            counter += 1
    if counter == len(X):
        return True
    else:
        return False

counter = 0
while Even(AA) == True:
    AA = [int(i / 2) for i in AA]
    counter += 1

print(counter)
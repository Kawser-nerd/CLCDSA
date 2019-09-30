n = int(input())
a = [int(i) for i in input().split()]

def odd_elm(num):
    x = num
    while True:
        if x%2==1:
            return x
        else:
            x = x//2

l = []
for x in a:
    l.append(odd_elm(x))

print(len(list(set(l))))
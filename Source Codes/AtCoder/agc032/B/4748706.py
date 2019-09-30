import numpy as np

def main():
    n = int(input())
    a = []
    b = []

    if n % 2:
        ma = n
    else:
        ma = n + 1
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i + j != ma and i < j:
                a.append(i)
                b.append(j)

    print(len(a))
    for i, j in zip(a, b):
        if i < j:
            print(i, j)


if __name__ == '__main__':
   main()
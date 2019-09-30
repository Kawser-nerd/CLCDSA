from collections import Counter

def main():
    n = int(input())
    s = [input() for _ in range(n)]

    counter = Counter()
    for line in s:
        counter.update(line)
    
    r = counter.get('R', 0)
    b = counter.get('B', 0)
    if r > b:
        print('TAKAHASHI')
    elif r < b:
        print('AOKI')
    else:
        print('DRAW')

main()
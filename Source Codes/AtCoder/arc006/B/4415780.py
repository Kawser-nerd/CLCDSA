def main():
    n, h  = map(int, input().split())
    m = [dict() for _ in range(h)]

    for i in range(h):
        line = input()
        for j in range(n - 1):
            if line[j * 2 + 1] == '-':
                m[i][j] = j + 1
                m[i][j+1] = j
    
    line = input()
    for i in range(n):
        if line[i * 2] == 'o':
            goal = i
            break
    
    pos = goal
    for i in reversed(range(h)):
        if pos in m[i]:
            pos = m[i][pos]

    print(pos+1)

main()
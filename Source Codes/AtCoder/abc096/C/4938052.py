def main():
    input = sys.stdin.readline
    try:
        H,W = map(int,input().split())
        s = [list(input()) for _ in range(H)]
        dir4 = ((0, 1), (0, -1), (1, 0), (-1, 0))
        for i in range(H):
            for j in range(W):
                if s[i][j] == ".": continue
                cnt = 0
                for d in dir4:
                    nx = i + d[0]
                    ny = j + d[1]
                    if not (0 <= nx < H): continue
                    if not (0 <= ny < W): continue
                    if s[nx][ny] == "#": cnt += 1
                if cnt == 0:
                    print("No")
                    exit()
        print("Yes")
        
    finally:
        input = None

import sys; sys.setrecursionlimit(50000)
if __name__ == "__main__":
    main()
#!/usr/bin/env python3

adj_list = None


def solve(n):

    r = 0
    for i in range(2):
        visited = [False] * n
        dr = 0
        st = []
        v = r
        visited[v] = True
        st.append((v, 0))
        while len(st):
            v, d = st.pop()
            if dr < d:
                r, dr = v, d
            for w in adj_list[v]:
                if not visited[w]:
                    visited[w] = True
                    st.append((w, d + 1))
        if i == 0:
            x = r
        else:
            y = r


    return "{} {}".format(x + 1, y + 1)


def main():
    global adj_list

    n = input()
    n = int(n)
    adj_list = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = input().split()
        a = int(a) - 1
        b = int(b) - 1
        adj_list[a].append(b)
        adj_list[b].append(a)

    print(solve(n))


if __name__ == '__main__':
    main()
A,B,C,D = list(input())

def dfs(depth=0,op=""):
    if depth == 3:
        res = A + op[0] + B + op[1] + C + op[2] + D
        if eval(res) == 7:
            ans = res + "=7"
            print(ans)
            exit()
        return
    dfs(depth+1,op+"+")
    dfs(depth+1,op+"-")

dfs()
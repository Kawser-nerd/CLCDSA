__author__ = 'Reuben'



def solution(string,repeats):
    if eval_string_repeated(string, repeats) != (1,1):
        return "NO"

    i_found = False
    j_found = False
    s = string*min(repeats,8)
    for i in range(0,len(s)):
        for j in range(i+1,len(s)):
            if eval_string(s[0:i+1]) == ("i",0) and eval_string(s[i+1:j+1]) == ("j",0):
                return "YES"
    return "NO"


def eval_string(str):
    result = (1,0)
    for char in str:
        result = mult(result, char)
    return result

def eval_string_repeated(string, repeats):
    string = eval_string(string)
    repeats = repeats % 4
    result = (1,0)
    for r in range(0,repeats):
        result = mult(result,string)
    return result

def mult(a,b):
    if a[0] == 1:
        return (b[0],(a[1]+b[1])%2)
    if a[0] == b[0]:
        return (1,(a[1]+b[1]+1)%2)
    if a[0] == "i" and b[0] == "j":
        return("k",(a[1]+b[1])%2)
    if a[0] == "i" and b[0] == "k":
        return("j",(a[1]+b[1]+1)%2)
    if a[0] == "j" and b[0] == "k":
        return("i",(a[1]+b[1])%2)
    return mult((1,1),mult(b,a))

f_in = open('file.in')
f_out = open('file.out','w')

cases = int(f_in.readline())
for i in range(1,cases+1):
    print(i)
    repeats = int(f_in.readline().split()[1])
    string = [(c,0) for c in list(f_in.readline().strip())]
    s = solution(string, repeats)
    f_out.write("Case #"+str(i)+": "+s+"\n")


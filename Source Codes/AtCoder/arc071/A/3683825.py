import sys

def add_char(l, string):
    for s in string:
        l.append(s)

n = int(sys.stdin.readline().strip())
common_list = []

for i in range(n):
    s = sys.stdin.readline().strip()
    if i == 0:
        add_char(common_list, s)
    else:
        tmp = []
        add_char(tmp, s)
        tmp_c = list(common_list)
        for c in tmp_c:
            if c in tmp:
                tmp.remove(c)
            else:
                common_list.remove(c)
if len(common_list) == 0:
    print("")
else:
    common_list = sorted(common_list)
    s = ""
    for c in common_list:
        s += c
    print(s)
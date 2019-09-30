n = int(input())
SE = [list(input().split("-")) for _ in range(n)]

T = [0]*2401

def reS(string):
    if int(string[-1]) < 5:
        string = string[:-1]+"0"
    else:
        string = string[:-1]+"5"
    return int(string)

def reE(string):
    if string == "2400":
        string = string
    elif string[-1] == "0":
        string = string
    elif int(string[-1]) <= 5:
        string = string[:-1]+"5"
    else:
        if string[2] == "5":
            string = str(int(string[:-2])+1)+"00"
        else:
            string = string[:-2]+str(int(string[2])+1)+"0"
    return int(string)

for s,e in SE:
        T[reS(s)] += 1
        T[reE(e)] -= 1

ans = ""
temp = 0
flag = False
for i in range(2401):
    temp += T[i]
    if temp >= 1 and not(flag):
        flag = True
        ans += format(i,"04d")+"-"
    if flag and temp == 0:
        print(ans+format(i,"04d"))
        ans = ""
        flag = False
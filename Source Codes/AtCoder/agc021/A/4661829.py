n = input()
if (all([i == '9' for i in n[1:]])):
    print(int(n[0])+9*(len(n)-1))
else:
    print(int(n[0])-1+9*(len(n)-1))
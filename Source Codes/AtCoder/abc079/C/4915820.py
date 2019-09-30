import sys
A,B,C,D=input()
for a in ("-","+"):
    for b in ("-","+"):
        for c in ("-","+"):
            if eval(A+a+B+b+C+c+D)==7:
                print(A+a+B+b+C+c+D+"=7")
                sys.exit()
S = list(input())
while (True):
    del S[-2:]
    bunkatsu = int(len(S)/2)
    if (S[:bunkatsu] == S[bunkatsu:]):
        print(len(S))
        break
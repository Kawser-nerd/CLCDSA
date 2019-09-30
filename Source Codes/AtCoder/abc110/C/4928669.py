S = input()
T = input()
check = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
alll = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
alfa = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}
count_s = set()
count_t = set()
nums = 0
numt = 0
for s in range(len(S)):
    if count_s == alfa:
        break
    if S[s] in check:
        continue
    count_s.add(S[s])
    S = S.replace(S[s],str(alll[nums]))
    nums += 1
for t in range(len(T)):
    if count_t == alfa:
        break
    if T[t] in check:
        continue
    count_t.add(T[t])
    T = T.replace(T[t],str(alll[numt]))
    numt += 1
if S == T:
    print('Yes')
else:print('No')
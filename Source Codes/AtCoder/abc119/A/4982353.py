from datetime import datetime

S = list(map(int,input().split('/')))

today = datetime(S[0], S[1], S[2])

if today <= datetime(2019,4,30):
    print("Heisei")
else:
    print("TBD")
N = int(input())

S = input()

start_set = []
#0???1???????????
start_set.append("SS") 
start_set.append("SW")
start_set.append("WS")
start_set.append("WW")

def listed_goal_set(i):
    goal_set = []
    if S[i] == "o":
        goal_set.append("SSS")
        goal_set.append("WSW")
        goal_set.append("WWS")
        goal_set.append("SWW")
    else:
        goal_set.append("WSS")
        goal_set.append("SSW")
        goal_set.append("WWW")
        goal_set.append("SWS")
    return goal_set
    
goal_set1 = listed_goal_set(0)
goal_set2 = listed_goal_set(-1)
    
isok = False
for st in start_set:
    O = []
    O.append(st[0])
    O.append(st[1])
    for i in range(1,N-1):
        if O[i-1]=="S":
            if O[i]=="S": 
                if S[i]=="o":
                    O.append("S") #SSS
                else:
                    O.append("W") #SSW
            else:
                if S[i]=="o":
                    O.append("W") #SWW
                else:
                    O.append("S") #SWS
                
        if O[i-1]=="W":
            if O[i]=="S":
                if S[i]=="o":
                    O.append("W") #WSW
                else:
                    O.append("S") #WSS
            else:
                if S[i]=="o":
                    O.append("S") #WWS
                else:
                    O.append("W") #WWW
    #print(O)
    goals1 = O[-1]+O[0]+O[1]
    goals2 = O[-2]+O[-1]+O[0]
    if goals1 in goal_set1 and goals2 in goal_set2:
        isok = True
        break
                
if isok:
    print("".join(O))
else:
    print("-1")
S = input()
T = input()

matched_index = -1
for i in range(len(S)-len(T)+1) :
    s = S[i:i+len(T)]
    for j in range(len(T)) :
        if (s[j] != "?" and s[j] != T[j]) :
            break
    else :
        # ???????????????????????
        matched_index = i

if (matched_index > -1) :
    out_str = S[0:matched_index] + T + S[matched_index+len(T):]
    out_str = out_str.replace("?", "a")
    print(out_str)
else :
    print("UNRESTORABLE")
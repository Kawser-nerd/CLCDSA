S = input()
T = "WBWBWWBWBWBW"
d = {0:"Do", 2:"Re", 4:"Mi", 5:"Fa", 7:"So", 9:"La", 11:"Si"}
for i in range(12):
    if all (T[j] == S[j] for j in range(12)):
        print(d[i])
        break
    else:
        T = T[1:] + T[0]
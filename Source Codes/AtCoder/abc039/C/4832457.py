S = input()
dic_scale = {
    "WBWBWWBWBWBWWBWBWWBW" : "Do",
    "WBWWBWBWBWWBWBWWBWBW" : "Re",
    "WWBWBWBWWBWBWWBWBWBW" : "Mi",
    "WBWBWBWWBWBWWBWBWBWW" : "Fa",
    "WBWBWWBWBWWBWBWBWWBW" : "So",
    "WBWWBWBWWBWBWBWWBWBW" : "La",
    "WWBWBWWBWBWBWWBWBWWB" : "Si"
}

ans = dic_scale[S]
print(ans)
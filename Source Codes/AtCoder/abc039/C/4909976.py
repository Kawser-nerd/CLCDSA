s = input()
if s[:11] == "WBWBWWBWBWB":
    ans = "Do"
elif s[:9] == "WBWWBWBWB":
    ans = "Re"
elif s[:7] == "WWBWBWB":
    ans = "Mi"
elif s[:6] == "WBWBWB":
    ans = "Fa"
elif s[:11] == "WBWBWWBWBWW":
    ans = "So"
elif s[:9] == "WBWWBWBWW":
    ans = "La"
elif s[:7] == "WWBWBWW":
    ans = "Si"
print(ans)
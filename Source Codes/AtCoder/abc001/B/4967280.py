a = int(input())
result = ""
if a < 100:
    result = "00"
elif 100 <= a <= 5000:
    result_temp = int(a * 10 / 1000)
    if result_temp < 10:
        result = "0" + str(result_temp)
    else:
        result = str(result_temp)
elif 6000 <= a <= 30000:
    result = str(int(a / 1000) + 50)
elif 35000 <= a <= 70000:
    result = str((int((a - 30000)/5/1000) + 80))
elif a > 70000:
    result = "89"
    

print(result)
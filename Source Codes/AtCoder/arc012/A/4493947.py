day=input()
print(0 if day=="Sunday" else ["Saturday","Friday","Thursday","Wednesday","Tuesday","Monday"].index(day))
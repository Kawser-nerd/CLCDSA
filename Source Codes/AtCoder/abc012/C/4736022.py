max = 2025
kuku = int(input()) 
diff = max-kuku
for i in range(1,10):
    
    if i * 9 < diff or diff< i:
        continue
    for j in range(1,10):
        if i*j == diff:
            print("{} x {}".format(i,j))
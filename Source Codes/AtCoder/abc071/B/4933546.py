s = list(input())
alpha = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
for x in s:
    if x in alpha:
        alpha.remove(x)
print(alpha[0] if len(alpha)>0 else "None")
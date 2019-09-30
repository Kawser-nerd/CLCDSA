st = input()[0:12]
st *= 2 

n =  st.find("WWBWBWBWW")
L1 = ["Mi","Re","Do"]
L2 = ["Si","La","So","Fa"]

if n % 2 == 0:
   print( L1[n // 2] )
else:
    print (L2[n // 2 - 2])
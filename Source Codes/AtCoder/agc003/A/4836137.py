a=input()
ans="Yes"
if "W"in a and"E"not in a:
  ans="No"
elif "E"in a and"W"not in a:
  ans="No"
elif "N"in a and"S"not in a:
  ans="No"
elif "S"in a and"N"not in a:
  ans="No"
print(ans)
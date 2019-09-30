def ans():
  day = input()
  if(day == "Sunday" or day == "Saturday"):
    res = 0
  elif(day == "Monday"):
    res = 5
  elif(day == "Tuesday"):
    res = 4
  elif(day == "Wednesday"):
    res = 3
  elif(day == "Thursday"):
    res = 2
  elif(day == "Friday"):
    res = 1
  print(res)
ans()
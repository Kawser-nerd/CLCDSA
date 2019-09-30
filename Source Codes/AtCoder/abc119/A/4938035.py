s=input()
if int(s[:4])<2019:
  print("Heisei")
elif int(s[:4])==2019 and int(s[5:7])<5:
  print("Heisei")
else:
  print("TBD")
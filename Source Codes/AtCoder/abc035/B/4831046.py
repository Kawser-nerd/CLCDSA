hoge=input()
t=input()

kyori_1=abs(hoge.count("U")-hoge.count("D"))
kyori_2=abs(hoge.count("R")-hoge.count("L"))
hatena=hoge.count("?")

if(t=="1"):
  print(kyori_1+kyori_2+hatena)
elif(t=="2" and hatena>kyori_1+kyori_2):
  print(len(hoge)%2)
else:
  print(kyori_1+kyori_2-hatena)
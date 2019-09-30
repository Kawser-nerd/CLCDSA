b=input();s=input();d="ABXY";a=[i+j for i in d for j in d]
print(min(len(s.replace(p,"!").replace(q,"?"))for p in a for q in a))
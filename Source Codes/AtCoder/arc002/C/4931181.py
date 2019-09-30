import re;b=input();s=input();d="ABXY";a=[i+j for i in d for j in d]
print(min(int(b)-len(re.findall("("+p+"|"+q+")",s))for p in a for q in a))
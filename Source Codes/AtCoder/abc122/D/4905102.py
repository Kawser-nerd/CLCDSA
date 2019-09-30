N = int(input())
mod = 10**9+7
data = dict([(i+j+k, 1) for i in "ACGT" for j in "ACGT" for k in "ACGT"])
data["AGC"] = 0
data["ACG"] = 0
data["GAC"] = 0

def check(text):
    one = text[0]
    two = text[1]
    three = text[2]
    four = text[3]
    if "AGC" in text:
        return False
    if "AGC" in two + one + three + four:
        return False
    if "AGC" in one + three + two + four:
        return False
    if "AGC" in one + two + four + three:
        return False
    return True


for i in range(N-3):
    new_data = dict([(i+j+k, 0) for i in "ACGT" for j in "ACGT" for k in "ACGT"])
    for s in data.keys():
        for c in "ACGT":
            if(not check(s+c)):
                continue
            new_data[s[1:]+c] += data[s]%mod
    data = new_data.copy()
print(sum(data.values())%mod)
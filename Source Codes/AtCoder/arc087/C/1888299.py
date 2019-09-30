def main():
    N,L = map(int,input().split())
    keys = []
    grundy_num=0
    if N==1:
        print("Alice")
        exit()
    for i in range(N):
        s = input()
        #merge node:
        while len(s)>0:
            if s[-1]=='1' and s[:-1]+'0' in keys:
                keys.remove(s[:-1]+'0')
                s = s[:-1]
            elif s[-1]=='0' and s[:-1]+'1' in keys:
                keys.remove(s[:-1]+'1')
                s = s[:-1]
            else:
                if s!="":
                    keys.append(s)
                break
    if len(keys):
        keys = sorted(keys,key=len,reverse=True)
        grundy_list = []
        while len(keys):
            j = keys[0]
            keys.remove(j)
            temp_s = list(reversed(bin(L-len(j)+1)))
            grundy_list.append(1 << temp_s.index('1'))
            if j[:-1]!="":
                keys.append(j[:-1])
            j = j[:-1]
            #merge node
            while len(j)>0:
                if j[-1]=='1' and j[:-1]+'0' in keys:
                    keys.remove(j[:-1]+'0')
                    keys.remove(j)
                    j = j[:-1]
                    if j!="":
                        keys.append(j)
                elif j[-1]=='0' and j[:-1]+'1' in keys:
                    keys.remove(j[:-1]+'1')
                    keys.remove(j)
                    j = j[:-1]
                    if j!="":
                        keys.append(j)
                else:
                    break
            keys = sorted(keys,key=len,reverse=True)
        grundy_num = grundy_list[0]
        for i in range(1,len(grundy_list)):
            grundy_num = grundy_num^grundy_list[i]
    print("Bob" if grundy_num==0 else "Alice")


if __name__=="__main__":
    main()
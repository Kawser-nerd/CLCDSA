N,C=map(int,input().split())

List_Odd=[[0,i] for i in range(11)]
List_Eve=[[0,i] for i in range(11)]

for _ in range(N):
    coler=int(input())
    if _%2==0:
        List_Odd[coler][0]+=1
    else:
        List_Eve[coler][0]+=1
        
List_Odd.sort(reverse=True)
List_Eve.sort(reverse=True)

if N%2==0:
    if List_Odd[0][1]!=List_Eve[0][1]:
        print((N-List_Odd[0][0]-List_Eve[0][0])*C)
    elif List_Odd[0][1]==List_Eve[0][1]:
        if List_Odd[0][0]>List_Eve[0][0]:
            print((N-List_Odd[0][0]-List_Eve[1][0])*C)
        elif List_Odd[0][0]<List_Eve[0][0]:
            print((N-List_Odd[1][0]-List_Eve[0][0])*C)
        else:
            if List_Odd[1][0]>=List_Eve[1][0]:
                print((N-List_Odd[1][0]-List_Eve[0][0])*C)
            else:
                print((N-List_Odd[0][0]-List_Eve[1][0])*C)
if N%2==1:
    if List_Odd[0][1]!=List_Eve[0][1]:
        print((N-List_Odd[0][0]-List_Eve[0][0])*C)
    elif List_Odd[0][1]==List_Eve[0][1]:
        if (N-List_Odd[0][0])<(N-List_Eve[0][0]):
            print((N-List_Odd[0][0]-List_Eve[1][0])*C)
        elif (N-List_Odd[0][0])>(N-List_Eve[0][0]):
            print((N-List_Odd[1][0]-List_Eve[0][0])*C)
        else:
            if (N-List_Odd[1][0])<=(N-List_Eve[1][0]):
                print((N-List_Odd[1][0]-List_Eve[0][0])*C)
            else:
                print((N-List_Odd[0][0]-List_Eve[1][0])*C)
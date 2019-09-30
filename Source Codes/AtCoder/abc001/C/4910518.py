# C
def round(x,d=0):
    p=10**d
    return (x*p*2+1)//2/p

def check_Dir(deg, dis):
    n_dis = round(dis / 60, 1)
    
    if(n_dis>=0 and n_dis<=0.2):
        W = 0
    elif(n_dis>=0.3 and n_dis<=1.5):
        W = 1
    elif(n_dis>=1.6 and n_dis<=3.3):
        W = 2
    elif(n_dis>=3.4 and n_dis<=5.4):
        W = 3
    elif(n_dis>=5.5 and n_dis<=7.9):
        W = 4
    elif(n_dis>=8.0 and n_dis<=10.7):
        W = 5
    elif(n_dis>=10.8 and n_dis<=13.8):
        W = 6
    elif(n_dis>=13.9 and n_dis<=17.1):
        W = 7
    elif(n_dis>=17.2 and n_dis<=20.7):
        W = 8
    elif(n_dis>=20.8 and n_dis<=24.4):
        W = 9
    elif(n_dis>=24.5 and n_dis<=28.4):
        W = 10
    elif(n_dis>=28.5 and n_dis<=32.6):
        W = 11
    elif(n_dis>=32.7):
        W = 12
    
    if(deg >= 3600 * 1/32 and deg < 3600 * 3/32):
        Dir = "NNE"
    elif(deg >= 3600 * 3/32 and deg < 3600 * 5/32):
        Dir = "NE"
    elif(deg >= 3600 * 5/32 and deg < 3600 * 7/32):
        Dir = "ENE"
    elif(deg >= 3600 * 7/32 and deg < 3600 * 9/32):
        Dir = "E"   
    elif(deg >= 3600 * 9/32 and deg < 3600 * 11/32):
        Dir = "ESE"
    elif(deg >= 3600 * 11/32 and deg < 3600 * 13/32):
        Dir = "SE"
    elif(deg >= 3600 * 13/32 and deg < 3600 * 15/32):
        Dir = "SSE"
    elif(deg >= 3600 * 15/32 and deg < 3600 * 17/32):
        Dir = "S"
    elif(deg >= 3600 * 17/32 and deg < 3600 * 19/32):
        Dir = "SSW"
    elif(deg >= 3600 * 19/32 and deg < 3600 * 21/32):
        Dir = "SW"
    elif(deg >= 3600 * 21/32 and deg < 3600 * 23/32):
        Dir = "WSW"
    elif(deg >= 3600 * 23/32 and deg < 3600 * 25/32):
        Dir = "W"
    elif(deg >= 3600 * 25/32 and deg < 3600 * 27/32):
        Dir = "WNW"
    elif(deg >= 3600 * 27/32 and deg < 3600 * 29/32):
        Dir = "NW"
    elif(deg >= 3600 * 29/32 and deg < 3600 * 31/32):
        Dir = "NNW"
    else:
        Dir = "N"
        
    if(W==0):
        Dir = "C"
    
    
    return Dir, W

deg, dis = map(int, input().split())
Dir, W = (check_Dir(deg, dis))
print(Dir,W)
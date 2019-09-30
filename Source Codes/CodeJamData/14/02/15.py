def bestCookieTime(c,f,x):
    zero_time=cookieTime(c,f,x,0)
    best_time=zero_time
    total_farms=1000
    new_time=cookieTime(c,f,x,total_farms)
    while new_time<best_time:
        total_farms+=1000
        best_time=new_time
        new_time=cookieTime(c,f,x,total_farms)
    total_farms-=1900
    if total_farms<10:
        total_farms=10
    best_time=zero_time
    new_time=cookieTime(c,f,x,total_farms)
    while new_time<best_time:
        total_farms+=100
        best_time=new_time
        new_time=cookieTime(c,f,x,total_farms)
    total_farms-=190
    if total_farms<10:
        total_farms=10
    best_time=zero_time
    new_time=cookieTime(c,f,x,total_farms)
    while new_time<best_time:
        total_farms+=10
        best_time=new_time
        new_time=cookieTime(c,f,x,total_farms)
    total_farms-=19
    if total_farms<1:
        total_farms=1
    best_time=zero_time
    new_time=cookieTime(c,f,x,total_farms)
    while new_time<best_time:
        total_farms+=1
        best_time=new_time
        new_time=cookieTime(c,f,x,total_farms)
    return str(best_time)

def cookieTime(c,f,x,total_farms):
    if x<c:
        return x/2
    farms=0
    time=0
    cookie_rate=2
    while farms<total_farms:
        time+=c/cookie_rate
        cookie_rate+=f
        farms+=1
    return time+x/cookie_rate


input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        line = lines[num+1].split(" ")
        outputfile.write("Case #"+str(num+1)+": "+bestCookieTime(float(line[0]),float(line[1]),float(line[2]))+"\n")

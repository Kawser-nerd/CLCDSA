import datetime

def main() :
    date_str = input().split("/")
    y = date_str[0]
    m = date_str[1]
    d = date_str[2]
    date = datetime.datetime(int(y),int(m),int(d))
    while True :
        if (int(date.year) % (int(date.month) * int(date.day)) == 0) :
            print("{0:04d}/{1:02d}/{2:02d}".format(date.year,date.month,date.day))
            return
        
        date += datetime.timedelta(days=1)
            


main()
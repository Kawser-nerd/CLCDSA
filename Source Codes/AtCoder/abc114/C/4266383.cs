using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		// ????t?F?[?Y
        long N = long.Parse(Console.ReadLine());

        long cnt = 0;
        long ret = 0;
        while(true)
        {
            // cnt??1????????????
            cnt++;

            // 4?i????l????cnt=(ex)111 ??555??N???????I??
            if (stopCount(cnt, N)) break;

            // cnt??753???????????
            if (is753Num(cnt, N)) ret += 1;
        }
        //?o??
        Console.WriteLine(ret);
    }
    static bool is753Num(long cnt, long N)
    {
        // cnt(3?i???j??0,1,2??????????????true
        bool exist0 = false, exist1 = false, exist2 = false, exist4 = false;


        while(cnt > 0)
        {
            switch (cnt % 4)
            {
                case 1:
                    exist0 = true;
                    break;
                case 2:
                    exist1 = true;
                    break;
                case 3:
                    exist2 = true;
                    break;
                case 0:
                    exist4 = true;
                    break;
            }
            cnt /= 4;
        }
        bool e = exist0 && exist1 && exist2;

        //Console.WriteLine(cnt + " " + e);
        return (exist0 && exist1 && exist2 && !exist4);
    }

    static bool stopCount(long cnt, long N)
    {
        string S = "";
        //Console.Write(cnt + " " + N + " " );
        while(cnt > 0)
        {
            switch(cnt%4)
            {
                case 1:
                    S = "3" + S;
                    break;
                case 2:
                    S = "5" + S;
                    break;
                case 3:
                    S = "7" + S;
                    break;
            }
            cnt /= 4;
        }
        //Console.WriteLine(S);
        long convCnt = long.Parse(S);
        if (convCnt > N) return true;
        else return false;
    }

}
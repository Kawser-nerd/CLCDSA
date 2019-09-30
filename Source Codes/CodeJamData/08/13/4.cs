using System;

class B
{
	public static decimal value;
    public static int n;
    static void work_ans()
    {
        int i,j;
        decimal ans = 1;
        for (i = 1; i <= n; i++) ans = ans * value;
        String res = ans.ToString();
        for (i = 0;; i++) if (res[i] == '.') break;
        //Console.WriteLine(res);
        for (j = i - 3; j < i; j++) if (j < 0) Console.Write("0"); else Console.Write(res[j]);
        Console.WriteLine();
    }
    public static int Main()
	{
        int t = int.Parse(Console.ReadLine());
        int i;
        value = 5.2360679774997896964091736687313M;
        value = (decimal)5.2360679;//7749978 9696409 1736687313;
        decimal temp = 7.749978M;  temp /= 100000000;
        value += temp;
        temp = 9.696409M;  temp /= 100000000;  temp /= 10000000; value += temp;
        temp = 1.736687313M; temp /= 100000000;  temp /= 10000000;  temp /= 10000000;  value += temp;
        for (i = 1; i <= t; i++)
        {
            Console.Write("Case #");
            Console.Write(i);
            Console.Write(": ");
            n = int.Parse(Console.ReadLine());
            work_ans();
        }
		return 0;
	}
}

using System;
class MainClass
{
    public static void Main(string[] args)
    {

        string[] s1 = Console.ReadLine().Split(' ');
        long X = long.Parse(s1[0]);
        long Y = long.Parse(s1[1]);
        int ans = 0;

        long i = X;

        while(i<=Y)
        {

            ans++;

            i = i * 2;

        }
            
        //for (int i = X; i <= Y;i++)
        //{
         


        //}


        Console.WriteLine(ans);

    }
}
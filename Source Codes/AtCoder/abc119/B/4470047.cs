using System;
class Program
{
    static void Main(string[] args)
    {
        const double RATE = 380000.0;
        // ?
        double ans = 0.0;

        // ??
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            string[] tmp = Console.ReadLine().Split(' ');
            double a = double.Parse(tmp[0]);
            string b = tmp[1];

            if (b.Equals("JPY"))
            {
                ans += a;
            }
            else
            {
                ans += (a * RATE);
            }
        }
        
        //??
        Console.WriteLine(ans);
    }
}
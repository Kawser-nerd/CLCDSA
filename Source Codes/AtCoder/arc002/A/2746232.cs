using System;
class Program
{
	static void Main(string[] args)
	{
            var Y = decimal.Parse(Console.ReadLine());

            var rule1 = Y % 4 == 0;
            var rule2 = Y % 100 != 0;
            var rule3 = Y % 400 == 0;

            if (rule1)
            {
                if (rule2)
                {
                    Console.WriteLine("YES");
                    return;
                }
                else
                {
                    if (rule3)
                    {
                        Console.WriteLine("YES");
                        return;
                    }
                }
            }
            Console.WriteLine("NO");
	}
}
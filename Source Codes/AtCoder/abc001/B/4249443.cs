using System;

class Atcoder106
{
    public static void Main()
    {
        int m = int.Parse(Console.ReadLine());

        if (m < 100)
            Console.WriteLine("00");

        else if (m >= 100 && m <= 5000)
        {
            int m2 = m / 100;
            if (m2 < 10)
            {
                string m2s = m2.ToString();
                Console.WriteLine("0" + m2s);
            }
            else
                Console.WriteLine(m2);
        }

        else if (m >= 6000 && m <= 30000)
            Console.WriteLine(m / 1000 + 50);

        else if (m >= 35000 && m <= 70000)
            Console.WriteLine((m / 1000 - 30) / 5 + 80);

        else
            Console.WriteLine("89");
    }
}
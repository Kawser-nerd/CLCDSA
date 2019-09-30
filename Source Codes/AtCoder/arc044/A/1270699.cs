using System;

namespace arc044_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            switch (n)
            {
                case (1):
                    {
                        Console.WriteLine("Not Prime");
                        break;
                    }
                case (2):
                    {
                        Console.WriteLine("Prime");
                        break;
                    }
                case (3):
                    {
                        Console.WriteLine("Prime");
                        break;
                    }
                case (4):
                    {
                        Console.WriteLine("Not Prime");
                        break;
                    }
                case (5):
                    {
                        Console.WriteLine("Prime");
                        break;
                    }
                default:
                    {
                        int sum = 0;
                        string x = n.ToString();
                        for (int i = 0; i < x.Length; i++)
                        {
                            sum += int.Parse(x[i].ToString());
                        }
                        Console.WriteLine(sum % 3 != 0 && int.Parse(x[x.Length - 1].ToString()) % 5 != 0 && n % 2 != 0 ? "Prime" : "Not Prime");
                        break;
                    }
            }
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main()
        {
            var line = Console.ReadLine();
            int n = int.Parse(line.Split()[0]);
            int a = int.Parse(line.Split()[1]);
            int b = int.Parse(line.Split()[2]);
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                int digit = 0;
                int ni = i;
                while (ni > 0)
                {
                    digit += ni % 10;
                    ni /= 10;
                }
                if (a <= digit && digit <= b) ans+=i;
            }
            Console.WriteLine(ans);
        }
    }
}
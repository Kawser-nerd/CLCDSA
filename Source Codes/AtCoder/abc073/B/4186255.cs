using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Piza
{
    class Paiza
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = 0;
            for (int i = 0; i < N; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                ans += int.Parse(s[1])-int.Parse(s[0])+1;
            }
            Console.WriteLine(ans);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_006_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] t = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int bonus = int.Parse(Console.ReadLine());
         int[]me = Console.ReadLine().Split().Select(int.Parse).ToArray();
           List<int> a = new List<int> { };
            Array.Sort(t);
            Array.Sort(me);
            /*??*/
            if (t[0] == me[0] && t[1] == me[1] && t[2] == me[2] && t[3] == me[3] && t[4] == me[4] && t[5] == me[5]) { Console.WriteLine("1"); }
            else
            {
                for (int i = 0; i < 6; i++)
                {
                    a.Add(t[i]);
                }
                int chigaxtuta = -1;
                int ans = 0;
                for (int i = 0; i < 6; i++)
                {
                    if (a.IndexOf(me[i]) >= 0) { ans++; }
                    else if (chigaxtuta == -1 && me[i] == bonus) { chigaxtuta = i + 1; }
                    else if (chigaxtuta != -1) { chigaxtuta = -2; }
                }
                if (ans == 3) { Console.WriteLine("5"); }
                else if (ans < 3) { Console.WriteLine("0"); }
                else if (ans == 4) { Console.WriteLine("4"); }
                else if (ans == 5) { if (chigaxtuta > -1) { Console.WriteLine("2"); } else { Console.WriteLine("3"); } }
            }
            Console.ReadLine();
            
        }
    }
}
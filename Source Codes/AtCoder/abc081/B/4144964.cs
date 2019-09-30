using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{

    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] Ass = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            
            int ans = 0;
            bool flug = true;
            while (flug == true)
            {
                for (int i = 0; i < N; i++)
                {
                    if (Ass[i] % 2 != 0)
                    {
                        flug = false;
                        break;
                    }else{
                        Ass[i] = Ass[i]/2;
                    }
                }
                if(flug==true){
                    ans++;
                }
            }
            Console.WriteLine(ans);
        }
    }
}
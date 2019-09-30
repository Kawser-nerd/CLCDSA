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
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int C = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());
            int ans = 0;
            for (int i = 0; i <=A ; i++)
            {
                for (int j = 0; j <=B ; j++)
                {
                    for (int k  = 0; k<=C ; k++)
                    {
                      if(X - (500 * i + 100 * j + 50 * k)==0){
                        ans++;
                      }
                    }
                }
            }
          Console.WriteLine(ans);
        }
    }
}
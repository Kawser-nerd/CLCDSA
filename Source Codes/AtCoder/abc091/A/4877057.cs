using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp??
{
    class Program
    {
        static void Main(string[] args)
        {
            int a,b,c;
            string[] str;
            int ans;

            str=Console.ReadLine().Split(' ');

            a=int.Parse(str[0]);
            b=int.Parse(str[1]);
            c=int.Parse(str[2]);

            if(a+b>=c){
                Console.Write("Yes");
            } else {
                Console.Write("No");
            }
        }
    }
}
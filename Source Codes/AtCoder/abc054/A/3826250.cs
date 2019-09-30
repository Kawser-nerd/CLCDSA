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
            string[]s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);int b = int.Parse(s[1]);

            if(a==1){
                a += 13;
            }
            if(b==1){
                b += 13;
            }
            string ans = "";
            if(a>b){
                ans = "Alice";
            }else if(a<b){
                ans = "Bob";
            }else{
                ans = "Draw";
            }
            Console.WriteLine(ans);
        }
    }
}
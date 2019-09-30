using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Atcoder
{
    class aaaa
    {
        static void Main(string[] args)
        {
            string N  = Console.ReadLine();

            string ans ="No";
            for (int i =0;i<N.Length-2;i++){
                    string target= N.Substring(i,3);
                    if(target[0] == target[1] && target[1] == target[2] ){
                        ans = "Yes";
                    }
            }
            
            Console.WriteLine(ans);
            
        }
    }
}
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
            string s = Console.ReadLine();
            string ans = "AC";
            if(s.StartsWith("A")==false){
                ans="WA";
            }
            int cnt=0;
            for(int i =1;i<s.Length;i++){
                if(Char.IsUpper(s[i])){
                    if(i==1||i==s.Length-1||s[i] != 'C'){
                        ans = "WA";
                    }
                    cnt++;
                }
            }
            if(cnt!=1){
                ans="WA";
            }
            Console.WriteLine(ans);
        }
    }
}
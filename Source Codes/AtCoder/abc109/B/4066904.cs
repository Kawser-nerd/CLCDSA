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
            List<string> set = new List<string>();
            string ans = "Yes";
            for(int i =0;i<N;i++){
                string obj = Console.ReadLine();
                if(set.Contains(obj)){
                    ans = "No";
                    break;
                }else{
                    set.Add(obj);
                }
                if(i>0){
                    if(set[i-1].EndsWith(obj.Substring(0,1))==false){
                        ans = "No";
                        break;
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}
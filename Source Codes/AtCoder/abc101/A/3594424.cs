using System;
using System.Linq;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //?????????
            String str = Console.ReadLine();
            int ans = 0;
            for (int i =0;i<4;i++){
                if(str[i] == '+'){
                    ans++;
                } else{
                    ans--;
                }
            }
            Console.WriteLine(ans);
        }
    }
}
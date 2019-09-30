using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var targetChars = new Char[] { 'A','T','C','G' };
            var maxLenght = 0;
            var matchCnt = 0;
 
            var inputChars = input.ToCharArray();
            for (var i=0;i<inputChars.Length;i++)
            {
                var isMatch = false;
                // ATCG???????????????
                foreach (var targetChar in targetChars)
                {
                    if (inputChars[i] == targetChar)
                    {
                        isMatch = true;
                        break;
                    }
                }
 
                if (isMatch)
                {
                    matchCnt++;
                    if(matchCnt > 0 && matchCnt > maxLenght)
                    maxLenght = matchCnt;
                }
                else
                {
                    matchCnt = 0;
                }
 
            }
 
            Console.WriteLine(maxLenght);
        }
    }
 
}
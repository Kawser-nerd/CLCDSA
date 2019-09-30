using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    
    class Program
    {

        const int INF = -1000000000;

        static int[] CreateMaxDigitLevel(int matchnum, int[] usenumber, int[] neednum)
        {           
            int[] maxdigitlev = new int[matchnum + 1];
            maxdigitlev[0] = 0;
           
            for(int nowmatch = 1; nowmatch <= matchnum; nowmatch++)
            {
                int max = INF;
                for(int j = 0; j < usenumber.Length; j++)
                {
                    int tmp_matchnum = nowmatch - neednum[usenumber[j]];
                    if(tmp_matchnum < 0)
                    {
                        continue;
                    }
                    int digit = maxdigitlev[tmp_matchnum] + 1;
                    if(digit > max && digit >= 0)
                    {
                        max = digit;
                    }
                }

                maxdigitlev[nowmatch] = max;
            }

            return maxdigitlev;
        }

        static string DesicionMaxDigitNum(int[] maxdigitlev, int[] neednum, int[] usenumber, int matchnum, int usenumbernum)
        {

            string maxstr = "";
           
            int nowmatchnum = matchnum;
            for(int nowdigit = maxdigitlev[matchnum]; nowdigit > 0; nowdigit--)
            {               
                for(int j = 0; j < usenumbernum; j++)
                {
                    int next_matchnum = nowmatchnum - neednum[usenumber[j]];
                    if(next_matchnum < 0)
                    {
                        continue;
                    }
                    
                    if(maxdigitlev[next_matchnum] == maxdigitlev[nowmatchnum] - 1)
                    {                       
                        nowmatchnum = next_matchnum;
                        maxstr += usenumber[j].ToString();
                        break;
                    }
                }
                
            }

            return maxstr;
        }
        
        static void Main(string[] args)
        {

            int[] neednum = new int[10];
            neednum[1] = 2;
            neednum[2] = 5;
            neednum[3] = 5;
            neednum[4] = 4;
            neednum[5] = 5;
            neednum[6] = 6;
            neednum[7] = 3;
            neednum[8] = 7;
            neednum[9] = 6;

            string[] str = Console.ReadLine().Split(' ');
            int matchnum = int.Parse(str[0]);
            int usenumbernum = int.Parse(str[1]);

            int[] usenumber = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int[] maxdigitlev = new int[matchnum + 1];

            Array.Sort(usenumber);          
            Array.Reverse(usenumber);       
            
            maxdigitlev = CreateMaxDigitLevel(matchnum, usenumber, neednum);

            string ansstr = DesicionMaxDigitNum(maxdigitlev, neednum, usenumber, matchnum, usenumbernum);

            Console.WriteLine(ansstr);

        }
    }
}
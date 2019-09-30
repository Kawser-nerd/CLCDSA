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
          string[] s = Console.ReadLine().Split(' ');
          int p = 0;
          int w = 0;
          int g = 0;
          int y = 0;
          for (int i = 0; i <N ; i++)
          {
              if(s[i]=="P"){
                  p++;
              }else if(s[i]=="W"){
                  w++;
              }else if (s[i]=="G")
              {
                  g++;
              }else if (s[i]=="Y"){
                  y++;
              }
          }
          int ans = 0;
              if(p>0){
                  ans++;
              }
              if (w>0){
                  ans++;
              }
              if(g>0){
                  ans++;
              }
              if (y>0){
                  ans++;
              }
              Console.WriteLine(ans>3?"Four":"Three");
        }
    }
}
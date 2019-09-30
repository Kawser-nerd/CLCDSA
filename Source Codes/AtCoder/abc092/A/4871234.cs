using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
 {
        static void Main(string[] args)
        {
    		int a,b,c,d;
          	int ans;
//            string[] str = Console.ReadLine().Split(' ');

          	a = int.Parse(Console.ReadLine());
            b = int.Parse(Console.ReadLine());
          	c = int.Parse(Console.ReadLine()); 
            d = int.Parse(Console.ReadLine());

          	if(a>b){
              ans=b;
            }else{
              ans=a;
            }
          
          	if(c>d){
              ans=ans+d;
            }else{
              ans=ans+c;
            }
              
          	Console.Write("{0}",ans);
        }
 }
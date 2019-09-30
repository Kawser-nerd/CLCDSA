using System;

class Program
{
 static void Main(string[] args)
 {
   int cnt1;
   int cnt2;
   int[] cashNum = {-1,-1,-1};
   int sum = 0;
   bool bk = false;
   
   string[] str = Console.ReadLine().Split(' ');
   int num = int.Parse(str[0]);
   int cash = int.Parse(str[1]);
   
   for( cnt1 = 0; cnt1 <= num; cnt1++ )
   {
    for( cnt2 = 0; cnt2 <= (num - cnt1); cnt2++ )
    {
      sum = ( 10000 * cnt1 ) + ( 5000 * cnt2 ) + ( 1000 * (num - cnt1 - cnt2) );
      if( cash == sum ) {
        cashNum[0] = cnt1;
        cashNum[1] = cnt2;
        cashNum[2] = (num - cnt1 - cnt2);
        bk = true;
      }
    }
     
     if(bk)
     {
       break;
     }
   }
   
   Console.WriteLine("{0} {1} {2}", cashNum[0], cashNum[1], cashNum[2] );
 }
}
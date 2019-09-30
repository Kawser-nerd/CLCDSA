using System;

class Program
{
 static void Main(string[] args)
 {
   int coin500;
   int coin100;
   int coin50;
   int sum;
   int buff;
   int loop500;
   int loop100;
   int loop50;
   int cnt500 = 0;
   int cnt100 = 0;
   int cnt50 = 0;
   int paternNum = 0;
   
   coin500 = int.Parse(Console.ReadLine());
   coin100 = int.Parse(Console.ReadLine());
   coin50 = int.Parse(Console.ReadLine());
   sum = int.Parse(Console.ReadLine());
   
   buff = sum / 500;
   loop500 = ( coin500 > buff ? buff : coin500 );
   buff = sum / 100;
   loop100 = ( coin100 > buff ? buff : coin100 );
   buff = sum / 50;
   loop50 = ( coin50 > buff ? buff : coin50 );
   
   do
   {
     for( cnt100 = 0; cnt100 <= loop100; cnt100++ )
     {
       for( cnt50 = 0; cnt50 <= loop50; cnt50++ )
       {
         if( sum == ( ( 500 * cnt500 ) + ( 100 * cnt100 ) + ( 50 * cnt50 ) ) )
         {
           paternNum++;
         }
       }
     }
     cnt500++;
   }while(cnt500 <= loop500);
   
   Console.WriteLine(paternNum);
 }
}
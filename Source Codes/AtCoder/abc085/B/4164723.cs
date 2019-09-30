using System;

class Program
{
 static void Main(String[] args)
 {
   var total = 0;
   var cnt = 0;
   var max = 0;
   var dansu = 0;

   total = int.Parse(Console.ReadLine());
   
   int[] mochiCM = new int[total];
   
   for( cnt = 0; cnt < total; cnt++ )
   {
     mochiCM[cnt] = int.Parse(Console.ReadLine());
   }

   Array.Sort(mochiCM);
   
   foreach( var mochi in mochiCM )
   {
     if( max < mochi )
     {
       max = mochi;
       dansu++;
     }
   }
   
   Console.WriteLine(dansu);
 }
}
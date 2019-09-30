using System;

class Program
{
 static void Main(String[] args)
 {
   var str = Console.ReadLine().Split(' ');
   int[] buttonPushSec = new int[4];
   int bothPushSec = 0;
   int endSec = 0;
   int startSec = 0;
   
   buttonPushSec[0] = int.Parse(str[0]);
   buttonPushSec[1] = int.Parse(str[1]);
   buttonPushSec[2] = int.Parse(str[2]);
   buttonPushSec[3] = int.Parse(str[3]);
   
   if( ( buttonPushSec[1] > buttonPushSec[2] ) && ( ( buttonPushSec[2] > buttonPushSec[0] ) || ( buttonPushSec[3] > buttonPushSec[0] ) ) )
   {
       endSec = ( ( buttonPushSec[1] > buttonPushSec[3] )? buttonPushSec[3]: buttonPushSec[1] );
       startSec = ( ( buttonPushSec[0] > buttonPushSec[2] )? buttonPushSec[0]: buttonPushSec[2] );

       bothPushSec = endSec - startSec;
   }
   
   Console.WriteLine(bothPushSec);
 }
}
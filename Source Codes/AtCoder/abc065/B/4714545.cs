using System;

class Program
{
 static void Main(string[] args)
 {
   int num = int.Parse(Console.ReadLine());
   int cnt = 0;
   int pushNum = 0;
   int readPos = 0;
   
   string[] button = new string[num];
   
   for( cnt = 0; cnt < num; cnt++ )
   {
     button[cnt] = Console.ReadLine();
   }
   
   for( cnt = 0; cnt < num; cnt++ )
   {
     pushNum++;
     
     if( button[readPos] == "2" )
     {
		break;
     }
     else
     {
      readPos = int.Parse(button[readPos]) - 1;
     }
   }
   
   if( cnt == num )
   {
     pushNum = -1;
   }
   
   Console.WriteLine(pushNum);
 }
}
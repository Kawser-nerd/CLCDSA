using System;
using System.Collections.Generic;

class Program
{
 static void Main(string[] args)
 {
   int total = int.Parse(Console.ReadLine());
   string[] numStrArray = Console.ReadLine().Split(' ');
   int[] numArray = new int[total];
   int cnt = 0;
   int buff;
   bool no_error = true;
   List<int> listValue = new List<int>();
   
   for( cnt = 0; cnt < total; cnt++ )
   {
     buff = int.Parse(numStrArray[cnt]);
     numArray[cnt] = buff;
     
     if( buff > (cnt+1) )
     {
       no_error = false;
       break;
     }
   }

   if(no_error)
   {
     for( cnt = 0; cnt < total; cnt++ )
     {
       if( cnt == 0 )
       {
          listValue.Add(numArray[cnt]);
       }
       else
       {  
         buff = (listValue.Count - (numArray[cnt] - 1));
         if( buff == listValue.Count)
         {
          listValue.Add(numArray[cnt]);
         }
         else
         {
           listValue.Insert(buff, numArray[cnt]);
         }
       }
     } 
   }
   
   if(no_error)
   {
     listValue.Reverse();
     foreach( int i in listValue )
     {
       Console.WriteLine(i);
     }
   }
   else
   {
     Console.WriteLine(-1);
   }
 }
}
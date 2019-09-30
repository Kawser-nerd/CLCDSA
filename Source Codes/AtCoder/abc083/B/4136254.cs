using System;

class Program
{
 static void Main(string[] args)
 {
   string[] numStr;
   string cntStr;
   var valN = 0;
   var minNum = 0;
   var maxNum = 0;
   var sum = 0;
   var cnt1 = 0;
   var cnt2 = 0;
   var digit = 0;
   var digitSum =0;
   
   numStr = Console.ReadLine().Split(' ');
   
   valN = int.Parse(numStr[0]);
   minNum = int.Parse(numStr[1]);
   maxNum = int.Parse(numStr[2]);
   
   for( cnt1 = 0; cnt1 <= valN; cnt1++ )
   {
     digitSum = 0;
     cntStr = cnt1.ToString();
     digit = cnt1.ToString().Length;  
     
     for( cnt2 = 0; cnt2 < digit; cnt2++ )
     {
       digitSum += int.Parse(cntStr[cnt2].ToString());
     }
     
     if( ( minNum <= digitSum ) && ( digitSum <= maxNum ) )
     {
       sum += cnt1;
     }
   }
   
   Console.WriteLine(sum);
 }
}
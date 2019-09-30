using System;

class Program
{
 static void Main(String[] args)
 {
   var cardNum = 0;
   var cnt = 0;
   var cardDiffNum = 0;
   string[] cardStr;
   
   cardNum = int.Parse(Console.ReadLine());
   cardStr = Console.ReadLine().Split(' ');
   
   int[] card = new int[cardNum];
   
   for( cnt = 0; cnt < cardNum; cnt++ )
   {
     card[cnt] = int.Parse(cardStr[cnt]);
   }
   
   Array.Sort(card);
   Array.Reverse(card);
   
   for( cnt = 0; cnt < cardNum; cnt++ )
   {
     if( ( cnt % 2 ) == 0 )
     {
       cardDiffNum += card[cnt];
     }
     else
     {
       cardDiffNum -= card[cnt];
     }
   }
   
   Console.WriteLine(cardDiffNum);
 }
}
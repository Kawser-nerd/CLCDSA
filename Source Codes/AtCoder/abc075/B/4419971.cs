using System;

class Program
{
 static void Main( string[] args ) 
 {
   int cnt1,cnt2,cnt3,cnt4 = 0;
   int x,y = 0;
   String[] strBuff = new String[2];
   String strBuff2;
   int bomCnt = 0;
   
   strBuff = Console.ReadLine().Split(' ');
   x = int.Parse(strBuff[0]) + 2;
   y = int.Parse(strBuff[1]) + 2;

   Char[,] minesweep = new Char[x,y];
   Array.Clear(minesweep, 0, minesweep.Length); 
   
   
   for(cnt1 = 1; cnt1 < (x-1); cnt1++)
   {
     strBuff2 = Console.ReadLine();
     for(cnt2 = 1; cnt2 < (y-1); cnt2++)
     {
       minesweep[cnt1,cnt2] = strBuff2[cnt2-1];
     }
   }

   
   for(cnt1 = 1; cnt1 < (x-1); cnt1++)
   {
     for(cnt2 = 1; cnt2 < (y-1); cnt2++)
     {
       bomCnt = 0;
       
       if( minesweep[cnt1,cnt2] == '.' )
       {
         for(cnt3 = -1; cnt3 <= 1; cnt3++)
         {
          for(cnt4 = -1; cnt4 <= 1; cnt4++)
          {
            if( minesweep[(cnt1-cnt3),(cnt2-cnt4)] == '#' )
            {
              bomCnt++;
            }
          }
         }
        
         minesweep[cnt1,cnt2] = Char.Parse(bomCnt.ToString());
       }
       else
       {
         /* nothing */
       }
     }
   }
   
   for(cnt1 = 1; cnt1 < (x-1); cnt1++)
   {
     for(cnt2 = 1; cnt2< (y-1); cnt2++)
     {
       Console.Write(minesweep[cnt1,cnt2]);
     }
     Console.WriteLine();
   }
 }
}
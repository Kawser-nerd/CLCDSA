using System;

class Program
{
  static void Main(String[] args)
  {
    var firstLine = Console.ReadLine().Split(' '); 
    int x = int.Parse(firstLine[0]) + 2;
    int y = int.Parse(firstLine[1]) + 2;
    int cnt1,cnt2,cnt3 = 0;
    String strBuff;
    char[,] mass = new char[x,y];
    bool result = true;

    Array.Clear(mass,0,mass.Length);

    for( cnt1 = 1; cnt1 < (x-1); cnt1++ )
    {
      strBuff = Console.ReadLine();
      
      for( cnt2 = 1; cnt2 < (y-1); cnt2++ )
      {
        mass[cnt1,cnt2] = strBuff[cnt2-1];
      }
    }
    
    for( cnt1 = 1; cnt1 < (x-1); cnt1++ )
    {
      for( cnt2 = 1; cnt2 < (y-1); cnt2++ )
      {
        if( ( mass[cnt1,cnt2] == '#' ) && ( mass[(cnt1-1),cnt2] != '#' ) &&
          ( mass[cnt1,cnt2-1] != '#' ) && ( mass[cnt1,cnt2+1] != '#' ) && 
          ( mass[(cnt1+1),cnt2] != '#' ) )
        {
          result = false;
          break;
        }
        else
        {
         /* ??? */ 
        }
      }
      
      if( result == false )
      {
        break;
      }
    }
    
    Console.WriteLine("{0}",(result?"Yes":"No"));
  }
}
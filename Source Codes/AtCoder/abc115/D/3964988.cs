using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
  static long putty=0;
  static long eat=0;
  static void Main(string[] args)
  {
    var split = Console.ReadLine().Split(' ');
    int level = int.Parse(split[0]);
    eat = long.Parse(split[1]);
    
    eatBurger(level);
        
    Console.WriteLine(putty);
  }
  
  static void eatBurger(int level){
    if(level == 0){      
      putty++;
      eat--;
      return;
    }
    
    var puttyL = Math.Pow(2, level+1)-1;
    var eatL = (Math.Pow(2, level+1)-1)*2-1;
    if(eatL<eat){
      putty += (long)puttyL;
      eat -= (long)eatL;
      return;
    }
    
    eat--;
    if(eat<=0) return;

    eatBurger(level-1);
    if(eat<=0) return;
  
    putty++;
    eat--;
    if(eat<=0) return;

    eatBurger(level-1);
    if(eat<=0) return;

    eat--;
    if(eat<=0) return;
  }
}
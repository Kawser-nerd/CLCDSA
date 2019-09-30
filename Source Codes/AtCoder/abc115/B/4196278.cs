using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var priceList = new List<int>();
        for(int i=0; i<10; i++){
          var temp = Console.ReadLine();
          if(String.IsNullOrEmpty(temp)){
            break; 
          }else{
            priceList.Add(int.Parse(temp));
          }
        }
        
        var sum = priceList.Sum();
        var max = priceList.Max();
        
        Console.WriteLine(sum - max/2);
    }
}
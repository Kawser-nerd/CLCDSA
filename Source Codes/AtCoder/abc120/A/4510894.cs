using System;
using System.Linq;

namespace ABC120A{
	public class Program{
  		public static void Main(){
  			var ABC = Console.ReadLine().Split().Select(int.Parse).ToList();
          	if(ABC[1]>ABC[0]*ABC[2]){
            	Console.WriteLine(ABC[2]);
               	return;
            }else{
            	Console.WriteLine(ABC[1]/ABC[0]);
              	return;
            }
        }
	}
}
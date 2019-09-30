using System;
using System.Linq;

namespace ABC120B{
	public class Program{
  		public static void Main(){
  			var ABK = Console.ReadLine().Split().Select(int.Parse).ToList();
          	var count = 0;
			var ans = ABK[0]>ABK[1]?ABK[1]:ABK[0];
			while(count != ABK[2]){
				if(ABK[0]%ans == 0&&ABK[1]%ans == 0)count++;
				ans--;
			}
			Console.WriteLine(ans+1);
        }
	}
}
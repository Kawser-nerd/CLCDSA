using System;
using System.Linq;
 
public class Program
{
	public static void Main()
	{
		string s = Console.ReadLine();
      int firstA = 0, lastZ = 0;
      for(int i = 0; i < s.Length; i++){
        if(s[i] == 'Z') lastZ = i;
      }
      for(int i = s.Length - 1; i >= 0;i--){
        if(s[i] == 'A') firstA = i;
      }
      
      Console.WriteLine(lastZ - firstA + 1);
      
	}
}
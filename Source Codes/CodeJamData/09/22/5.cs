using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] input = File.ReadAllLines( "input.txt");
			int n = int.Parse(input[0]);
			List<string> output = new List<string>();
			for( int i = 1; i <= n; i++)
			{
				output.Add( "Case #"+i+": " + Solve( input[i]));
			}
			File.WriteAllLines( "output.txt", output.ToArray());
		}

		private static string Solve(string s)
		{
			int i = s.Length - 1;

			while (i > 0 && s[i-1] >= s[i]) 
				i = i-1;
			if( i == 0)
			{
				s = "0"+s;
				return Solve(s);
			}

			int j = s.Length;

			while (s[j-1] <= s[i-1])
				j = j-1;

			// swap values at positions (i-1) and (j-1)
			s = Swap(s,i-1, j-1);    

			i++; j = s.Length;

			while (i < j)
			{
				s = Swap(s,i-1, j-1);
				i++;
				j--;
			}
			return s;
		}

		private static string Swap(string s, int i, int j)
		{
			if( i > j)
				return Swap( s, j, i);
			return s.Substring( 0, i)+s[j]+s.Substring( i+1, j-i-1)+s[i]+s.Substring( j+1);
		}
	}
}

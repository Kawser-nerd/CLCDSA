using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication2.Round1A
{
	class ProgramC
	{
		const decimal SQRT3_5 = 5.2360679774997896964091736687313m;

		public static void Main()
		{
			StreamReader reader;
			TextWriter writer;
			int numberOfCases;

			reader = new StreamReader( @"C:\Software\CodeJam\Round1A\C-small.in" );
			writer = new StreamWriter( @"C:\Software\CodeJam\Round1A\C-small.out" );
			//writer = Console.Out;

			// The first line of the input file contains the number of cases.
			numberOfCases = Int32.Parse( reader.ReadLine() );

			for ( int i = 0; i < numberOfCases; i++ )
			{
				int n = Int32.Parse( reader.ReadLine() );
				writer.WriteLine( "Case #{0}: {1:000}", ( i + 1 ), Decimal.Floor( Power( SQRT3_5, n ) ) );
			}

			writer.Flush();
			writer.Close();

			reader.Close();

			Console.ReadLine();
		}

		static decimal Power( decimal value, decimal power )
		{
			decimal result;

			result = value;
			for ( int i = 1, sz = (int)(power); i < sz; i++ )
			{
				result *= value;
				//result %= 1000;
			}

			return (result%1000);
		}
	}
}

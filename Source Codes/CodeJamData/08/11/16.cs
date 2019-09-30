using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

class Program
{
	static int Main ( string[] args )
	{
		string inFile = @"test.in.txt";
		inFile = @"A-small-attempt0.in.txt";
		//inFile = @"A-small-attempt1.in.txt";
		//inFile = @"A-small-attempt2.in.txt";
		//inFile = @"A-large.in.txt";

		string outFile = @"test.temp.txt";

		try
		{
			List<TestCase> list = ReadTests ( inFile );

			foreach ( TestCase test in list )
				test.Execute ();

			WriteResults ( list, outFile );

			return 0;
		}
		catch ( Exception exc )
		{
			Console.Write ( exc );
			return 1;
		}
	}
	private static List<TestCase> ReadTests ( string file )
	{
		List<TestCase> list = new List<TestCase> ( 100 );
		using ( StreamReader reader = new StreamReader ( file ) )
		{
			int N = Int32.Parse ( reader.ReadLine () );
			for ( int i = 0 ; i < N ; i++ )
				list.Add ( new TestCase ( reader ) );
		}
		return list;
	}
	private static void WriteResults ( List<TestCase> list, string file )
	{
		using ( StreamWriter writer = new StreamWriter ( file ) )
		{
			for ( int i = 0 ; i < list.Count ; i++ )
				list[ i ].Write ( writer, i + 1 );
		}
	}
}

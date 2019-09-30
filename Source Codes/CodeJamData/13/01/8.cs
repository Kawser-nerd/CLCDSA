using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemA
{
	internal class A
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\A-Large.in";
		private const string OutputFile = @"..\A-Large.out";

		private char[][] s;
		private string ans;

		void ReadData()
		{
			s = new char[4][];
			for ( int i = 0; i < 4; ++i )
			{
				s[i] = NextToken().ToCharArray();
				if ( s[i].Length != 4 ) throw new ApplicationException();
				foreach ( var c in s[i] )
				{
					if ( c != 'O' && c != 'X' && c != 'T' && c != '.' )
						throw new ApplicationException();
				}
			}
		}

		void Solve()
		{
			bool ok;
			for ( int i = 0; i < 4; ++i )
			{
				ok = true;
				for ( int j = 0; j < 4; ++j )
					if ( s[i][j] == '.' || s[i][j] == 'O' )
						ok = false;
				if ( ok )
				{
					ans = "X won";
					return;
				}
				ok = true;
				for ( int j = 0; j < 4; ++j )
					if ( s[j][i] == '.' || s[j][i] == 'O' )
						ok = false;
				if ( ok )
				{
					ans = "X won";
					return;
				}
			}
			ok = true;
			for ( int i = 0; i < 4; ++i )
				if ( s[i][i] == '.' || s[i][i] == 'O' ) ok = false;
			if ( ok )
			{
				ans = "X won";
				return;
			}
			ok = true;
			for ( int i = 0; i < 4; ++i )
				if ( s[3 - i][i] == '.' || s[3 - i][i] == 'O' ) ok = false;
			if ( ok )
			{
				ans = "X won";
				return;
			}


			for ( int i = 0; i < 4; ++i )
			{
				ok = true;
				for ( int j = 0; j < 4; ++j )
					if ( s[i][j] == '.' || s[i][j] == 'X' )
						ok = false;
				if ( ok )
				{
					ans = "O won";
					return;
				}
				ok = true;
				for ( int j = 0; j < 4; ++j )
					if ( s[j][i] == '.' || s[j][i] == 'X' )
						ok = false;
				if ( ok )
				{
					ans = "O won";
					return;
				}
			}
			ok = true;
			for ( int i = 0; i < 4; ++i )
				if ( s[i][i] == '.' || s[i][i] == 'X' ) ok = false;
			if ( ok )
			{
				ans = "O won";
				return;
			}
			ok = true;
			for ( int i = 0; i < 4; ++i )
				if ( s[3 - i][i] == '.' || s[3 - i][i] == 'X' ) ok = false;
			if ( ok )
			{
				ans = "O won";
				return;
			}

			ok = true;
			for ( int i = 0; i < 4; ++i )
				for ( int j = 0; j < 4; ++j )
					if ( s[i][j] == '.' ) ok = false;
			if ( !ok )
				ans = "Game has not completed";
			else
			{
				ans = "Draw";
			}
		}


		void WriteAnswer()
		{
			Out.WriteLine( ans );
		}

		#region ...

		void run()
		{
			if ( UseStandardIO )
			{
				_inputStream = Console.In;
				_outputStream = Console.Out;
			}
			else
			{
				_inputStream = File.OpenText( InputFile );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
			var solvers = new A[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new A();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) - 1 ).ForAll(
					solver => { solver.Solve(); Console.Title = ( ++done ).ToString() + " of " + testsCount; } );
			}
			else
			{
				for ( int i = 0; i < testsCount; ++i )
				{
					solvers[i].Solve();
					Console.Title = ( ++done ).ToString() + " of " + testsCount;
				}
			}
			for ( int i = 0; i < testsCount; ++i )
			{
				Out.Write( string.Format( "Case #{0}: ", i + 1 ) );
				solvers[i].WriteAnswer();
			}
			Out.Flush();
			if ( UseStandardIO )
			{
				Console.ReadLine();
			}
			else
			{
				Out.Close();
			}
		}

		static TextWriter Out { get { return _outputStream; } }

		private static TextReader _inputStream;
		private static TextWriter _outputStream;

		public BigInteger NextBigInteger()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return BigInteger.Parse( token );
		}

		public double NextDouble()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return double.Parse( token, CultureInfo.InvariantCulture );
		}

		public long NextLong()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return long.Parse( token );
		}

		public int NextInt()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return int.Parse( token );
		}

		private static readonly Queue<string> Tokens = new Queue<string>();
		public string NextToken()
		{
			if ( Tokens.Count > 0 )
			{
				return Tokens.Dequeue();
			}
			while ( Tokens.Count == 0 )
			{
				var line = _inputStream.ReadLine();
				if ( line == null ) return null;
				foreach ( var token in line.Split( _whiteSpaces, StringSplitOptions.RemoveEmptyEntries ) )
				{
					Tokens.Enqueue( token );
				}
			}
			return Tokens.Count == 0 ? null : Tokens.Dequeue();
		}

		private readonly char[] _whiteSpaces = { ' ', '\r', '\n', '\t' };

		static void Main()
		{
			new Thread( new A().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

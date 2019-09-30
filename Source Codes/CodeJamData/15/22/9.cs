//CONTEST_TOOL_SUBMIT:D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2015 1B\B.cs
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;
using kp.Algo;

namespace CodeJam
{
	class Solution
	{
		private const bool UseMultiThreading = false;
		private const bool IsTestingRun = false;
		private const string InputFile = @"C:\Users\kp\Downloads\B-large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2015 1B\B-Large.out";

		private int rows, cols, n;
		private int ans;

		void ReadData()
		{
			rows = NextInt();
			cols = NextInt();
			n = NextInt();
		}

		private bool[,] taken;
		void Solve()
		{
			ans = Solve( rows, cols, n );
		}

		int Solve( int rows, int cols, int n )
		{
			int ans = int.MaxValue;
			for ( int parity = 0; parity < 2; parity++ )
			{
				int need = n;
				bool[,] a = new bool[rows, cols];
				for ( int i = 0; i < rows && need > 0; i++ )
				{
					for ( int j = 0; j < cols && need > 0; j++ )
					{
						if ( ( i + j ) % 2 == parity )
						{
							a[i, j] = true;
							--need;
						}
					}
				}

				if ( need == 0 )
					return 0;

				var left = new List<int>();
				for ( int i = 0; i < rows && need > 0; i++ )
				{
					for ( int j = 0; j < cols && need > 0; j++ )
					{
						if ( ( i + j ) % 2 != parity )
						{
							int cnt = 0;

							if ( i > 0 && a[i - 1, j] ) ++cnt;
							if ( i < rows - 1 && a[i + 1, j] ) ++cnt;
							if ( j > 0 && a[i, j - 1] ) ++cnt;
							if ( j < cols - 1 && a[i, j + 1] ) ++cnt;

							left.Add( cnt );
						}
					}
				}

				left.Sort();
				int cur = 0;
				for ( int i = 0; i < need; i++ )
				{
					cur += left[i];
				}
				ans = Math.Min( ans, cur );
			}

			return ans;
		}

		private void Go( int r, int c, int need, int cur )
		{
			if ( need == 0 )
			{
				ans = Math.Min( ans, cur );
				return;
			}
			if ( r == rows )
			{
				return;
			}
			if ( c == cols )
			{
				Go( r + 1, 0, need, cur );
				return;
			}

			int left = ( rows - r - 1 ) * cols + cols - c;
			if ( left < need )
				return;
			Go( r, c + 1, need, cur );

			taken[r, c] = true;
			Go( r, c + 1, need - 1, cur + ( ( r > 0 && taken[r - 1, c] ) ? 1 : 0 ) + ( ( c > 0 && taken[r, c - 1] ) ? 1 : 0 ) );
			taken[r, c] = false;
		}

		void WriteAnswer()
		{
			Out.WriteLine( ans );
		}

		#region ...

		void run()
		{
			if ( IsTestingRun )
			{
				_inputStream = File.OpenText( "input.txt" );
				_outputStream = Console.Out;
			}
			else
			{
				_inputStream = File.OpenText( Path.Combine( Path.Combine( Environment.GetFolderPath( Environment.SpecialFolder.UserProfile ), "Downloads" ), InputFile ) );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
			var solvers = new Solution[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new Solution();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) ).ForAll(
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
			Out.Close();
			if ( IsTestingRun )
			{
				Console.WriteLine( "ALL DONE!" );
				Console.ReadLine();
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
			new Thread( new Solution().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

namespace kp.Algo { }

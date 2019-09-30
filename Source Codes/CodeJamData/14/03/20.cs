
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
		private const bool UseStandardIO = false;
		private const string InputFile = @"C-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 1A\C-Large.out";

		private int R, C, M;
		private char[][] Ans;

		void ReadData()
		{
			R = NextInt();
			C = NextInt();
			M = NextInt();
		}

		void Solve()
		{
			Ans = Solve( M, R, C );
			if ( Ans == null )
			{
				Ans = Solve( M, C, R );
				if ( Ans != null )
				{
					throw new Exception();
				}
			}
			else
			{
				if ( Solve( M, C, R ) == null )
					throw new Exception();
			}
		}

		char[][] Solve( int m, int r, int c )
		{
			char[][] ans;
			if ( m == 0 )
			{
				ans = new char[r][];
				for ( int i = 0; i < r; i++ )
				{
					ans[i] = new char[c];
				}
				ans[0][0] = 'c';
				return ans;
			}

			if ( m == r * c - 1 )
			{
				ans = new char[r][];
				for ( int i = 0; i < r; i++ )
				{
					ans[i] = new char[c];
					for ( int j = 0; j < c; j++ )
					{
						ans[i][j] = '*';
					}
				}
				ans[0][0] = 'c';
				return ans;
			}

			if ( r == 1 )
			{
				ans = new char[1][];
				ans[0] = new char[c];
				for ( int i = 0; i < m; ++i ) ans[0][i] = '*';
				ans[0][c - 1] = 'c';
				return ans;
			}

			if ( c == 1 )
			{
				ans = new char[r][];
				for ( int i = 0; i < r; i++ )
				{
					ans[i] = new char[1];
					if ( i < m ) ans[i][0] = '*';
				}
				ans[r - 1][0] = 'c';
				return ans;
			}

			for ( int x = 2; x <= c; ++x )
			{
				for ( int y = 2; y <= r; ++y )
				{
					for ( int z = 0; x - z >= 2; ++z )
					{
						int t = r * c - m - x * y;
						if ( t < 0 || t % ( x - z ) != 0 ) continue;
						t /= ( x - z );
						if ( t + y > r ) continue;

						ans = new char[r][];
						for ( int i = 0; i < r; i++ )
						{
							ans[i] = new char[c];
							for ( int j = 0; j < c; j++ )
							{
								if ( i < r - y - t )
								{
									ans[i][j] = '*';
								}
								else if ( i < r - y && j < c - x + z )
								{
									ans[i][j] = '*';
								}
								else if ( j < c - x )
								{
									ans[i][j] = '*';
								}
							}
						}
						ans[r - 1][c - 1] = 'c';
						return ans;
					}
				}
			}

			for ( int x = 1; x <= c - 2; ++x )
				for ( int y = 1; y <= r - 2; ++y )
					for ( int z = 0; x - z > 0; ++z )
					{
						int t = m - x * y;
						if ( t < 0 || t % ( x - z ) != 0 ) continue;
						t /= ( x - z );
						if ( t > c - 2 - y ) continue;

						ans = new char[r][];
						for ( int i = 0; i < r; i++ )
						{
							ans[i] = new char[c];
							for ( int j = 0; j < c; j++ )
							{
								if ( i < y && j < x )
								{
									ans[i][j] = '*';
								}
								else if ( i < y + t && j < x - z )
								{
									ans[i][j] = '*';
								}
							}
						}
						ans[r - 1][c - 1] = 'c';
						return ans;
					}

			return null;
		}

		void WriteAnswer()
		{
			Out.WriteLine();
			if ( Ans == null )
			{
				Out.Write( "Impossible" );

				//Out.Write( string.Format( "               {0} {1} {2}", R, C, M ) );

				Out.WriteLine();
			}
			else
			{
				if ( Ans.GetLength( 0 ) != R ) throw new Exception();
				int cntC = 0, cntStar = 0;
				foreach ( var row in Ans )
				{
					if ( row.GetLength( 0 ) != C ) throw new Exception();
					string s = "";
					foreach ( var ch in row )
					{
						if ( ch == 0 ) s += ".";
						else if ( ch == 'c' )
						{
							s += ch;
							++cntC;
						}
						else if ( ch == '*' )
						{
							s += ch;
							++cntStar;

						}
						else throw new Exception();
					}
					Out.WriteLine( s );
				}
				if ( cntC != 1 || cntStar != M )
					throw new Exception();
			}
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
			new Thread( new Solution().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

namespace kp.Algo { }

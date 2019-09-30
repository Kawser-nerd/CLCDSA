
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
		private const string InputFile = @"C-Small-attempt1.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 2C\C-Small.out";

		private int rows, cols, k, ans;

		void ReadData()
		{
			rows = NextInt();
			cols = NextInt();
			k = NextInt();
			if ( cols > rows )
			{
				int tmp = rows;
				rows = cols;
				cols = tmp;
			}
		}

		private bool[,] a;

		private int[] ll, rr, tt, bb;

		void Go( int row, int col )
		{
			if ( col == cols )
			{
				Go( row + 1, 0 );
				return;
			}
			if ( row == rows )
			{

				for ( int i = 0; i < rows; ++i )
				{
					ll[i] = int.MaxValue;
					for ( int j = 0; j < cols; ++j )
						if ( a[i, j] )
						{
							ll[i] = j;
							break;
						}

					rr[i] = int.MinValue;
					for ( int j = cols - 1; j >= 0; --j )
						if ( a[i, j] )
						{
							rr[i] = j;
							break;
						}
				}

				for ( int j = 0; j < cols; ++j )
				{
					tt[j] = int.MaxValue;
					for ( int i = 0; i < rows; ++i )
						if ( a[i, j] )
						{
							tt[j] = i;
							break;
						}

					bb[j] = int.MinValue;
					for ( int i = rows - 1; i >= 0; --i )
						if ( a[i, j] )
						{
							bb[j] = i;
							break;
						}
				}

				int enc = 0, tot = 0;
				for ( int i = 0; i < rows; ++i )
					for ( int j = 0; j < cols; ++j )
					{
						if ( ll[i] <= j && rr[i] >= j && tt[j] <= i && bb[j] >= i )
							++enc;
						if ( a[i, j] ) ++tot;
					}

				if ( enc >= k ) ans = Math.Min( ans, tot );

				return;
			}
			Go( row, col + 1 );

			a[row, col] = true;
			Go( row, col + 1 );
			a[row, col] = false;
		}

		void Solve()
		{
			ans = k;
			if ( Math.Min( rows, cols ) < 3 )
				return;
			a = new bool[rows, cols];
			ll = new int[rows];
			rr = new int[rows];
			tt = new int[cols];
			bb = new int[cols];
			Go( 0, 0 );
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

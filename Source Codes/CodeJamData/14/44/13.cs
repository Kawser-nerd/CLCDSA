
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
		private const string InputFile = @"D-Small-attempt0.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 3\D-Small.out";

		private const int MOD = 1000000007;
		private int n, serv, worst, cnt;
		private string[] s;

		void ReadData()
		{
			n = NextInt();
			serv = NextInt();
			s = new string[n];
			for ( int i = 0; i < n; ++i ) s[i] = NextToken();
		}

		void Solve()
		{
			worst = 0;
			for ( int mask = 0; mask < 1 << ( 2 * n ); ++mask )
			{
				var badMask = false;
				var a = new List<string>[serv];
				for ( int i = 0; i < serv; ++i ) a[i] = new List<string>();
				for ( int i = 0; i < n && !badMask; ++i )
				{
					int id = mask >> ( 2 * i ) & 3;
					if ( id >= serv )
					{
						badMask = true;
						break;
					}
					a[id].Add( s[i] );
				}
				for ( int i = 0; i < serv && !badMask; ++i )
					if ( a[i].Count == 0 ) badMask = true;

				if ( badMask ) continue;

				int wr = 0;
				for ( int i = 0; i < serv; ++i )
				{
					int[,] per = new int[100, 26];
					int tot = 1;
					foreach ( var ss in a[i] )
					{
						int cur = 0;
						foreach ( var ch in ss )
						{
							if ( per[cur, ch - 'A'] == 0 )
							{
								per[cur, ch - 'A'] = tot++;
							}
							cur = per[cur, ch - 'A'];
						}
					}
					wr += tot;
				}

				if ( wr > worst )
				{
					worst = wr;
					cnt = 1;
				}
				else if ( wr == worst ) ++cnt;
			}
		}

		void WriteAnswer()
		{
			Out.WriteLine( worst + " " + cnt );
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

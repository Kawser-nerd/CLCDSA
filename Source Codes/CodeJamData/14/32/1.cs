
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
		private const string InputFile = @"B-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 2C\B-Large.out";

		private int n;
		private string[] s;
		private int ans;

		private const int MOD = 1000000007;

		void ReadData()
		{
			n = NextInt();
			s = new string[n];
			for ( int i = 0; i < n; ++i ) s[i] = NextToken();
		}

		private int[,] edges;

		void Solve()
		{
			ans = 0;
			edges = new int[26, 26];
			for ( int i = 0; i < n; ++i )
			{
				var letters = new List<char>();
				for ( int j = 0; j < s[i].Length; )
				{
					int k = j + 1;
					while ( k < s[i].Length && s[i][k] == s[i][j] ) ++k;
					letters.Add( s[i][j] );
					j = k;
				}
				if ( letters.Distinct().Count() != letters.Count )
					return;
				if ( letters.Count < 3 )
				{
					edges[letters[0] - 'a', letters[letters.Count - 1] - 'a']++;
				}
				else
				{
					for ( int j = 1; j < letters.Count - 1; ++j )
					{
						for ( int l = 0; l < n; ++l )
							if ( l != i && s[l].IndexOf( letters[j] ) >= 0 ) return;
					}
					edges[letters[0] - 'a', letters[letters.Count - 1] - 'a']++;
				}
			}

			int[] to = new int[26];
			int[] from = new int[26];
			for ( int i = 0; i < 26; ++i )
			{
				to[i] = -1;
				from[i] = -1;
			}
			for ( int i = 0; i < 26; ++i )
			{
				for ( int j = 0; j < 26; ++j )
					if ( i != j && edges[i, j] > 0 )
					{
						if ( to[i] != -1 )
						{
							return;
						}
						to[i] = j;
						from[j] = i;
					}
				if ( to[i] != -1 && edges[i, to[i]] > 1 ) return;
			}

			int[] f = NumTheoryUtils.FactorialArray( 1000, MOD );
			bool[] was = new bool[26];
			int counted = 0;
			int curAns = 1;
			int chains = 0;
			for ( int i = 0; i < 26; ++i )
				if ( from[i] == -1 )
				{
					if ( to[i] != -1 || edges[i, i] > 0 ) ++chains;
					int u = i;
					while ( u != -1 && !was[u] )
					{
						was[u] = true;

						curAns = NumTheoryUtils.Mul( curAns, f[edges[u, u]], MOD );

						counted += edges[u, u] + ( to[u] == -1 ? 0 : 1 );
						u = to[u];
					}

					if ( u != -1 )
					{
						ans = 0;
						return;
					}
				}

			if ( counted != n )
			{
				ans = 0;
				return;
			}

			curAns = NumTheoryUtils.Mul( curAns, f[chains], MOD );
			ans = curAns;
		}

		void WriteAnswer()
		{
			Out.WriteLine( ( ans % MOD + MOD ) % MOD );
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

namespace kp.Algo
{
	static class NumTheoryUtils
	{
		public static int[] FactorialArray( int n, int mod )
		{
			int[] f = new int[n + 1];
			f[0] = 1;
			for ( int i = 1; i <= n; ++i ) f[i] = Mul( i, f[i - 1], mod );
			return f;
		}
		public static int Mul( int a, int b, int mod )
		{
			int res = (int)( ( (long)a * b ) % mod );
			if ( res < 0 ) res += mod;
			return res;
		}
	}
}

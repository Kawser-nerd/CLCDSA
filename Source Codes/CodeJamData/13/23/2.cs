
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
		private const bool UseMultiThreading = true;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel\Downloads\C-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2013 1B\C-Large.out";

		private static string[] lines;
		private string s;
		private int res;

		private static HashSet<string> words, prefixes;

		bool HasWord( string t )
		{
			lock ( words )
			{
				return words.Contains( t );
			}
		}

		bool HasPrefix( string t )
		{
			lock ( prefixes )
			{
				return prefixes.Contains( t );
			}
		}

		static void Precalc()
		{
			lines = File.ReadAllLines( @"D:\temp\garbled_email_dictionary.txt" );
			words = new HashSet<string>();
			prefixes = new HashSet<string>();
			foreach ( var line in lines )
			{
				words.Add( line );
				for ( int i = 1; i <= line.Length; ++i )
					prefixes.Add( line.Substring( 0, i ) );
			}
		}

		void ReadData()
		{
			s = NextToken();
		}

		private const int INF = 1000000;
		private int[,] dp;

		private int P, LEN, cur;
		char[] curS = new char[15];
		private int curSz;

		void Go2( int p, int last, int sum )
		{
			if ( p == LEN )
			{
				if ( HasWord( new string( curS, 0, curSz ) ) )
					cur = Math.Min( cur, sum + Go( P + LEN, last ) );
				return;
			}

			if ( curSz > 0 && !HasPrefix( new string( curS, 0, curSz ) ) )
				return;

			curS[curSz++] = s[P + p];
			Go2( p + 1, Math.Min( 5, last + 1 ), sum );
			--curSz;

			if ( last >= 5 )
			{
				for ( char cc = 'a'; cc <= 'z'; ++cc )
				{
					if ( cc == s[P + p] ) continue;

					curS[curSz++] = cc;
					Go2( p + 1, 1, sum + 1 );
					--curSz;
				}
			}
		}

		int Go( int pos, int last )
		{
			if ( pos == s.Length )
			{
				return 0;
			}
			if ( pos > s.Length )
				return INF;
			if ( dp[pos, last] != -1 )
				return dp[pos, last];
			int ans = INF;
			for ( int len = 1; len <= 10 && pos + len <= s.Length; ++len )
			{
				P = pos;
				LEN = len;
				cur = INF;
				curSz = 0;
				Go2( 0, last, 0 );
				ans = Math.Min( ans, cur );
			}

			return dp[pos, last] = ans;
		}

		void Solve()
		{
			dp = new int[s.Length, 6];
			for ( int i = 0; i < s.Length; ++i )
				for ( int j = 0; j < 6; ++j )
					dp[i, j] = -1;
			for ( int i = s.Length - 1; i >= 0; --i )
				for ( int j = 0; j < 6; ++j )
					Go( i, j );
			res = Go( 0, 5 );
		}

		void WriteAnswer()
		{
			Out.WriteLine( res );
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

			Precalc();

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

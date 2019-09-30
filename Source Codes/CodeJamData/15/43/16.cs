
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Threading;
using kp.Algo;

namespace CodeJam
{
	class Solution
	{
		private const bool UseMultiThreading = true;
		private const bool IsTestingRun = false;
		private const string InputFile = @"C:\Users\kp\Downloads\C-small-attempt1.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2015 2\C-Small-1.out";

		private int n;
		private string[][] words;
		private int ans;

		void ReadData()
		{
			n = NextInt();
			words = new string[n][];
			for ( int i = 0; i < n; i++ )
			{
				words[i] = _inputStream.ReadLine().Split( new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries );
			}
		}

		private Dictionary<string, int> all;

		int GetId( string s )
		{
			if ( all.ContainsKey( s ) )
				return all[s];
			var cnt = all.Count;
			all.Add( s, cnt );
			return all[s];
		}

		void Solve()
		{
			all = new Dictionary<string, int>();
			int[][] wordInts = new int[n][];
			for ( int i = 0; i < n; i++ )
			{
				wordInts[i] = new int[words[i].Length];
				for ( int j = 0; j < words[i].Length; j++ )
				{
					wordInts[i][j] = GetId( words[i][j] );
				}
			}
			var eng = new bool[n];
			eng[0] = true;
			ans = int.MaxValue;
			var a = new int[all.Count + 1];
			for ( int mask = 0; mask < 1 << ( n - 2 ); mask++ )
			{
				for ( int i = 0; i < n - 2; i++ )
				{
					if ( BitUtils.BitInMask( mask, i ) )
					{
						eng[i + 2] = true;
					}
					else
					{
						eng[i + 2] = false;
					}
				}
				Array.Clear( a, 0, a.Length );
				for ( int i = 0; i < n; i++ )
				{
					for ( int j = 0; j < words[i].Length; j++ )
					{
						if ( eng[i] ) a[wordInts[i][j]] |= 1;
						else a[wordInts[i][j]] |= 2;
					}
				}
				ans = Math.Min( ans, a.Count( c => c == 3 ) );
			}
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
				solvers.AsParallel().WithDegreeOfParallelism( Environment.ProcessorCount ).ForAll(
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

namespace kp.Algo
{
	static class BitUtils
	{
		public static bool BitInMask( int mask, int bit )
		{
			return ( mask & ( 1 << bit ) ) != 0;
		}
	}
}

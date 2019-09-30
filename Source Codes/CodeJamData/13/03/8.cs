using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;

namespace ProblemC
{
	class C
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\C-large-2.in";
		private const string OutputFile = @"..\C-Large-2.out";

		private BigInteger A, B;
		private long ans;

		void ReadData()
		{
			A = NextBigInteger();
			B = NextBigInteger();
		}

		List<long> Get( long a, long b )
		{
			var res = new List<long>();
			for ( long i = Math.Max( 1, (long)Math.Sqrt( a ) - 1 ); i <= (long)Math.Sqrt( b ) + 1; ++i )
			{
				var s = i.ToString();
				int l = 0, r = s.Length - 1;
				bool ok = true;
				while ( l < r )
				{
					if ( s[l] != s[r] )
					{
						ok = false;
						break;
					}
					++l;
					--r;
				}
				if ( !ok ) continue;

				long sq = i * i;

				s = sq.ToString();
				l = 0; r = s.Length - 1;
				ok = true;
				while ( l < r )
				{
					if ( s[l] != s[r] )
					{
						ok = false;
						break;
					}
					++l;
					--r;
				}
				if ( !ok ) continue;
				if ( sq >= a && sq <= b )
					res.Add( sq );
			}

			return res;
		}

		private static List<BigInteger> alls;
		private static char[] cur;

		static void Gen( int l )
		{
			cur = new char[l];
			for ( int i = 0; i < l; ++i ) cur[i] = '0';
			Go( 0, 0, l );
		}

		private static void Go( int pos, int sum, int l )
		{
			if ( sum >= 10 ) return;
			if ( pos > ( l - 1 ) / 2 )
			{
				alls.Add( BigInteger.Parse( new string( cur ) ) );
				return;
			}
			for ( int d = ( pos == 0 ? 1 : 0 ); d < 4; ++d )
			{
				cur[pos] = (char)( d + '0' );
				cur[l - pos - 1] = (char)( d + '0' );
				Go( pos + 1, sum + ( d * d ) * ( l - pos - 1 > pos ? 2 : 1 ), l );
				cur[pos] = '0';
				cur[l - pos - 1] = '0';
			}
		}

		static void Precalc()
		{
			alls = new List<BigInteger>();
			for ( int len = 1; len <= 51; ++len )
			{
				Gen( len );
			}
			alls.Sort();
		}

		BigInteger GetSquareRoot( BigInteger x )
		{
			if ( x == 1 ) return 1;
			BigInteger l = 1, r = x + 1, m;
			while ( l + 1 < r )
			{
				m = ( l + r ) / 2;
				if ( m * m <= x ) l = m;
				else r = m;
			}
			return l;
		}

		int Solve( BigInteger a, BigInteger b )
		{
			BigInteger l = GetSquareRoot( a ), r = GetSquareRoot( b );
			while ( l * l < a ) ++l;
			if ( l > r ) return 0;
			var low = alls.BinarySearch( l );
			if ( low < 0 ) low = ~low;
			var hi = alls.BinarySearch( r );
			if ( hi < 0 ) hi = ~hi;
			else hi++;
			return hi - low;
		}

		void Solve()
		{
			ans = Solve( A, B );
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

			C.Precalc();

			var solvers = new C[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new C();
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
			new Thread( new C().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

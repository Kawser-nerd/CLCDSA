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
		public const bool GenerateInput = false;
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\kp\Downloads\C-Large.in";
		private const string OutputFile = @"..\C-Large.out";

		private int n;
		private long[] a;
		private List<long> first, second;

		void ReadData()
		{
			n = NextInt();
			a = new long[n];
			for ( int i = 0; i < n; ++i ) a[i] = NextLong();
		}

		private Dictionary<long, int> h;
		private int shift;

		void go( int p, long sum, int mask )
		{
			if ( p == 15 )
			{
				if ( sum > 0 )
				{
					if ( h.ContainsKey( sum ) )
					{
						first = new List<long>();
						for ( int i = 0; i < 15; ++i )
							if ( ( mask & ( 1 << i ) ) != 0 ) first.Add( a[i + shift] );
						mask = h[sum] & ( ( 1 << 15 ) - 1 );
						int sh = ( h[sum] >> 15 );
						second = new List<long>();
						for ( int i = 0; i < 15; ++i )
							if ( ( mask & ( 1 << i ) ) != 0 ) second.Add( a[i + sh] );
					}
					else
					{
						h.Add( sum, mask + ( shift << 15 ) );
					}
				}
				return;
			}
			go( p + 1, sum, mask );
			if ( first != null ) return;
			go( p + 1, sum + a[p + shift], mask | ( 1 << p ) );
		}

		void Solve()
		{
			var rnd = new Random( 1234 );
			while ( true )
			{
				for ( int i = 1; i < n; ++i )
				{
					int j = rnd.Next( i + 1 );
					long tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
				h = new Dictionary<long, int>();
				for ( shift = 0; shift + 15 <= n; shift += 15 )
				{
					go( 0, 0, 0 );
					if ( first != null ) return;
				}
			}
		}

		void WriteAnswer()
		{
			if ( first == null )
			{
				throw new ApplicationException( "Must never be here" );
				Out.WriteLine( "Impossible" );
			}
			else
			{
				if ( first.Sum() != second.Sum() )
				{
					throw new ApplicationException( "Must never be here" );
				}

				if ( !first.Except( second ).Any() )
				{
					throw new ApplicationException( "Must never be here" );
				}
				for ( int i = 0; i < first.Count; ++i )
				{
					if ( i > 0 ) Out.Write( " " );
					Out.Write( first[i] );
				}
				Out.WriteLine();
				for ( int i = 0; i < second.Count; ++i )
				{
					if ( i > 0 ) Out.Write( " " );
					Out.Write( second[i] );
				}
				Out.WriteLine();
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
				_inputStream = File.OpenText( InputFile );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
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
				Out.WriteLine( string.Format( "Case #{0}:", i + 1 ) );
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
			if ( GenerateInput )
			{
				var rnd = new Random( 123 );
				var builder = new StringBuilder();
				builder.AppendLine( "10" );
				for ( int t = 0; t < 10; ++t )
				{
					int n = 500;
					builder.Append( n );
					for ( int i = 0; i < n; ++i )
					{
						long x = rnd.Next( 1000000 ) * 1000000L + rnd.Next( 1000000 );
						builder.Append( " " + x );
					}
					builder.AppendLine();
				}
				File.WriteAllText( InputFile, builder.ToString() );
			}
			else
			{
				new Thread( new C().run, 64 * 1024 * 1024 ).Start();
			}
		}

		#endregion
	}
}

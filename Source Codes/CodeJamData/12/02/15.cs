using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.GoogleCodeJamJapan2011
{
	class Problem
	{
		#region Main

		static string RESULTFILE = @"..\..\..\__out.txt";

		static void Main( string[] args )
		{
			if( 0 < args.Length ) {
				CASEFILE = args[0];
			} else if( 1 < args.Length ) {
				MAXTHREADS = int.Parse( args[1] );
			}

			DateTime startTime = DateTime.Now;

			int count;
			Problem[] testcases;

			using( TextReader reader = new StreamReader( CASEFILE ) ) {
				string line = reader.ReadLine();
				count = int.Parse( line );
				testcases = new Problem[count];

				for( int i = 0; i < count; i++ )
					testcases[i] = new Problem( reader );
			}

			Initialize();

			Thread[] threadPool = new Thread[MAXTHREADS];
			for( int t = 0; t < MAXTHREADS; t++ )
				threadPool[t] = null;

			for( int next = 0;; ) {
				if( count <= next ) {
					bool finished = true;
					for( int t = 0; t < MAXTHREADS; t++ )
						if( threadPool[t] != null && threadPool[t].IsAlive ) {
							finished = false;
							break;
						}
					if( finished )
						break;
				}

				for( int t = 0; t < MAXTHREADS; t++ ) {
					if( threadPool[t] != null && !threadPool[t].IsAlive )
						threadPool[t] = null;

					if( threadPool[t] == null && next < count ) {
						Console.WriteLine( "----------------------------------------------------- {0}/{1} ({2:F3}[sec])", next + 1, count, ( DateTime.Now - startTime ).TotalSeconds );
						testcases[next].WriteParams();

						threadPool[t] = new Thread( new ThreadStart( testcases[next++].Solv ) );
						threadPool[t].Start();
					}
				}

				Thread.Sleep( 100 );
			}

			Console.WriteLine( "\n#############################################################################\n" );
			using( TextWriter writer = new StreamWriter( RESULTFILE ) ) {
				for( int i = 0; i < count; i++ )
					testcases[i].WriteResult( writer, i + 1 );
			}

			TimeSpan span = DateTime.Now - startTime;
			Console.WriteLine( "\n#############################################################################\n" );
			Console.WriteLine( "{0:F3}[sec] = {1:F3}[min]", span.TotalSeconds, span.TotalMinutes );
			if( BEEP )
				Console.Beep( 1000, 5000 );
			Console.ReadKey();
		}


		string Result;

		private void WriteResult( TextWriter writer, int number )
		{
			writer.WriteLine( "Case #{0}: {1}", number, Result );
			Console.WriteLine( "Case #{0}: {1}", number, Result );
		}

		#endregion


		////////////////////////////////
		long N;
		long S;
		long p;
		long[] t;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			N = long.Parse( strs[0] );
			S = long.Parse( strs[1] );
			p = long.Parse( strs[2] );

			t = new long[N];
			for( int i = 0; i < N; i++ ) {
				t[i] = long.Parse(strs[3 + i]);
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2}", N, S, p );
			for( int i = 0; i < N; i++ )
				Console.Write( " {0}", t[i] );
			Console.WriteLine();
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

//		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
		static string CASEFILE = @"..\..\..\B-large.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////



		private void Solv()
		{
			////////////////////////////////
			List<long> tt = new List<long>();
			long r = 0;
			long ss = 0;
			long sl = 0;
			long so = 0;
			long se = 0;

			for( int i = 0; i < N; i++ ) {
				long x = t[i] / 3;
				long y = t[i] - x - x;
				if( y - x == 2 ) {
					ss++;
					if( p < y )
						so++;
					else if( y < p )
						sl++;
					else
						se++;
				}
				if( x == y && (p - 1) == y && 0 < x) {
					ss++;
					se++;
					r++;
				}
				if( p <= y )
					r++;
			}

			if( ss > S ) {
				ss -= sl;
				if( ss > S ) {
					ss -= so;
					if( ss > S ) {
						r -= ss - S;
						if( se < ss - S )
							Console.WriteLine( "!!!!!!!!!!!!!!!!!!!!!!!!! error !!!!!!!!!!!!!!!!!!");
					}
				}
			}
/*
			if( ss < S ) {
				long q = S - ss;
				if( cl <= q ) {
					r += cl;
				} else {
					r += q;
					cl -= q;
					r += Math.Min(cl,so);
				}
			} else if( ss > S ) {
				ss -= sl;
				if( ss > S ) {
					ss -= so;
					if( ss > S ) {
						r -= ss - S;
						if( se < ss - S )
							Console.WriteLine( "!!!!!!!!!!!!!!!!!!!!!!!!! error !!!!!!!!!!!!!!!!!!");
					}
				}
			}
*/

			Result = r.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}

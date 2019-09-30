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
		int A;
		int B;
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
			A = int.Parse( strs[0] );
			B = int.Parse( strs[1] );
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", A, B );
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 4;
		static bool BEEP = false;
//		static string CASEFILE = @"..\..\..\C-small-attempt0.in";
		static string CASEFILE = @"..\..\..\C-large.in";
//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////


/* small
		private class Res {
			public int n;
			public int m;
			public Res( int n, int m ) { this.n = n; this.m = m; }
		}
		private List<Res> rlist = new List<Res>();

		private void Add( int n, int m ) {
			foreach( Res r in rlist ) {
				if( r.n == n && r.m == m )
					return;
			}
			rlist.Add( new Res(n, m) );
		}

		private void Solv()
		{
			////////////////////////////////
			for( int n = A; n <= B; n++ ) {
				int x = (int)Math.Log10(n);
//				Console.WriteLine( "x = {0}", x );

				int y = 10;
				for( int i = 0; i < x; i++ ) {
					int a = n / y;
					int b = n % y;
					int z = b * (int)Math.Pow(10, x - i) + a;
					if( n < z && A <= z && z <= B ) {
						Add( n, z );
//						Console.WriteLine( "({0},{1}) ", n, z );
					}
					y *= 10;
				}
			}

			Result = rlist.Count.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}
*/
		private void Solv()
		{
			////////////////////////////////
			int r = 0;

			for( int n = A; n <= B; n++ ) {
				int x = (int)Math.Log10(n);
//				Console.WriteLine( "x = {0}", x );

				HashSet<int> ms = new HashSet<int>();
				int y = 10;
				int yy = (int)Math.Pow(10, x);
				for( int i = 0; i < x; i++ ) {
					int a = n / y;
					int b = n % y;
					int z = b * yy + a;
					if( n < z && A <= z && z <= B ) {
						ms.Add(z);
//						Console.WriteLine( "({0},{1}) ", n, z );
					}
					y *= 10;
					yy /= 10;
				}
				r += ms.Count;
			}

			Result = r.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}

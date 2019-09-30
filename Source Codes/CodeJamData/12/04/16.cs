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
		int H;
		int W;
		int D;
		int[,] m;
		int hx,hy;
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
			H = int.Parse( strs[0] );
			W = int.Parse( strs[1] );
			D = int.Parse( strs[2] );

			m = new int[W, H];
			for( int i = 0; i < H; i++ ) {
				line = reader.ReadLine();
				for( int j = 0; j < W; j++ )
					if( line[j] == '#' )
						m[j,i] = 1;
					else if( line[j] == '.' )
						m[j,i] = 0;
					else {
						m[j,i] = 2;
						hx = j;
						hy = i;
					}
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2}", W, H, D );
/*
			for( int i = 0; i < H; i++ ) {
				for( int j = 0; j < W; j++ )
					Console.Write( "{0} ", m[j,i] );
				Console.WriteLine();
			}
*/
			Console.WriteLine("-----");
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

		static string CASEFILE = @"..\..\..\D-small-attempt1.in";
//		static string CASEFILE = @"..\..\..\D-large.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////

		private class Q {
			public int dx;
			public int dy;
			public Q( int a, int b ) { dx = a; dy = b; }
		}



		private void Solv()
		{
			////////////////////////////////
			int WW = W - 2;
			int HH = H - 2;
			int cx = D/WW+1;
			int cy = D/HH+1;
			int rx = cx*2+1;
			int ry = cy*2+1;
			int[,] mm = new int[ WW*rx, HH*ry ];

			for( int i = 0; i < ry; i++ ) {
				bool yrev = false;
				if( (i % 2) != (cy%2) )
					yrev = true;

				for( int j = 0; j < rx; j++ ) {
					bool xrev = false;
					if( (j % 2) != (cx%2) )
						xrev = true;

					if( xrev ) {
						if( yrev ) {
							for( int y = 0; y < HH; y++ )
								for( int x = 0; x < WW; x++ )
									mm[ WW*j + x, HH*i + y ] = m[ WW - x, HH - y ];
						} else {
							for( int y = 0; y < HH; y++ )
								for( int x = 0; x < WW; x++ )
									mm[ WW*j + x, HH*i + y ] = m[ WW - x, y + 1 ];
						}
					} else {
						if( yrev ) {
							for( int y = 0; y < HH; y++ )
								for( int x = 0; x < WW; x++ )
									mm[ WW*j + x, HH*i + y ] = m[ x + 1, HH - y ];
						} else {
							for( int y = 0; y < HH; y++ )
								for( int x = 0; x < WW; x++ )
									mm[ WW*j + x, HH*i + y ] = m[ x + 1, y + 1 ];
						}
					}
				}
			}


			List<Q> r = new List<Q>();
			int hcx = cx*WW + hx - 1;
			int hcy = cy*HH + hy - 1;
			Console.WriteLine( "hc = ({0}, {1})", hcx, hcy );
			Console.WriteLine("-----");

			for( int y = 0; y < HH*ry; y++ ) {
				for( int x = 0; x < WW*rx; x++ ) {
//					Console.Write( "{0} ", mm[x,y] );
					if( mm[x, y] == 2 && !( x == hcx && y == hcy ) ) {
						int dx = x - hcx;
						int dy = y - hcy;
						double d = Math.Sqrt( dx*dx + dy*dy );
						if( d <= D ) {
//							Console.WriteLine( "    ({0}, {1}) -> ({2}, {3}) : {4}", x, y, dx, dy, d );
							bool found = false;
							foreach(Q q in r) {
								if( q.dx*dy == q.dy*dx ) {
									if( dx != 0 ) {
										if( 0 < dx * q.dx ) {
											found = true;
											break;
										}
									} else {
										if( 0 < dy * q.dy ) {
											found = true;
											break;
										}
									}
								}
							}
							if( !found ) {
								r.Add( new Q( dx, dy ) );
//								Console.WriteLine( "        !!!!!");
							}
						}
					}
				}
//				Console.WriteLine();
			}

			Result = r.Count.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}

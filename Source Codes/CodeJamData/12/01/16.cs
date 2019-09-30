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
		string G;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			G = reader.ReadLine();
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0}", G );
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

		static string CASEFILE = @"..\..\..\A-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\__in_sample.txt";
		////////////////////////////////



		private void Solv()
		{
			////////////////////////////////
/*
			string[] tb = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
							"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
							"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
			string[] ta = { "our language is impossible to understand",
							"there are twenty six factorial possibilities",
							"so it is okay if you want to just give up" };
			char[] cm = new char[26];

			for( int i = 0; i < 26; i++ )
				cm[i] = '-';
			
			for( int t = 0; t < 3; t++ ) {
				for( int i = 0; i < tb[t].Length; i++ ) {
					if( 'a' <= tb[t][i] ) {
						cm[ tb[t][i] - 'a' ] = ta[t][i];
					}
				}
			}
			for( int i = 0; i < 26; i++ )
				Console.Write( (char)('a' + i) );
			Console.WriteLine();
			for( int i = 0; i < 26; i++ )
				Console.Write( cm[i] );
			Console.WriteLine();
*/
			//abcdefghijklmnopqrstuvwxyz
			//yhesocvxduiglbkr-tnwjpfma-

			string table = "yhesocvxduiglbkrztnwjpfmaq";

			for( int i = 0; i < G.Length; i++ ) {
				if( 'a' <= G[i] ) {
					Result += table[ G[i] - 'a' ];
				} else {
					Result += ' ';
				}
			}
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}

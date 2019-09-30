import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.System.out;

public class A {
	// int 2.1 x 10^9
	// long 9.2 x 10^18
	static Scanner in = new Scanner(System.in);
	
	static BufferedReader _in = new BufferedReader(new InputStreamReader(System.in));
	static String _string;
	static StringTokenizer _stok;
	
	static String nextLine() throws IOException {
		_string = _in.readLine();
		_stok = new StringTokenizer(_string);
		return _string;
	}
	static String nextTok()		{return _stok.nextToken();}
	static int nextInt()		{return Integer.parseInt(nextTok());} // 2.1 x 10^9, 
	static long nextLong()		{return Long.parseLong(nextTok());}   // 9.2 x 10^18, 
	static float nextFloat()	{return Float.parseFloat(nextTok());}
	static double nextDouble() 	{return Double.parseDouble(nextTok());}
	static BigInteger nextBig()	{return new BigInteger(nextTok());}
	static void Dprint(Object s)   {if (debug) System.out.print(s);}
	static void Dprintln(Object s) {if (debug) System.out.println(s);}
	static void Dprintln()         {if (debug) System.out.println();}
	static void Dprintf(String s, Object... args) {if (debug) System.out.printf(s, args);}
	
	static boolean debug = false;

	public static void main(String[] args) throws Exception {
		nextLine();
		int Cases = nextInt();
		for (int Case=0; Case<Cases; Case++) {
			nextLine();
			int R = nextInt();
			int C = nextInt();
			char[][] tiles = new char[R][C];
			for (int i=0; i<R; i++) {
				String s = nextLine();
				for (int j=0; j<C; j++) {
					tiles[i][j] = s.charAt(j);
				}
			}
			boolean ok = true;
			for (int i=0; i<R && ok; i++) {
				for (int j=0; j<C && ok; j++) {
					if (tiles[i][j] == '#') {
						tiles[i][j] = '/';
						if (j+1<C && tiles[i][j+1] == '#') {
							tiles[i][j+1] = '\\';
						} else {
							ok = false;
							break;
						}
						if (i+1<R && tiles[i+1][j] == '#') {
							tiles[i+1][j] = '\\';
						} else {
							ok = false;
							break;
						}
						if (i+1<R && j+1<C && tiles[i+1][j+1] == '#') {
							tiles[i+1][j+1] = '/';
						} else {
							ok = false;
							break;
						}
					}
				}
			}
			out.println("Case #" + (Case+1) + ": ");
			if (ok) {
				for (int i=0; i<R && ok; i++) {
					for (int j=0; j<C && ok; j++) {
						out.print(tiles[i][j]);
					}
					out.println();
				}
			} else {
				
				out.println("Impossible");
			}
			
		} // end for each case

	} // end main
	
}

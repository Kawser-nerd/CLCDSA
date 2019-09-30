import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.System.out;

public class BB {
	static BufferedReader _in = new BufferedReader(new InputStreamReader(System.in));
	static String _string;
	static StringTokenizer _stok;
	static String nextLine() throws IOException {
		_string = _in.readLine();
		_stok = new StringTokenizer(_string);
		return _string;}
	static String nxt() {return _stok.nextToken();}
	static String nxw() {while (!_stok.hasMoreTokens())
		try {nextLine();} catch (IOException e) {e.printStackTrace();}
		return _stok.nextToken();}
	static int nxi()		{return Integer.parseInt(nxw());} // 2.1 x 10^9, 
	static long nxl()		{return Long.parseLong(nxw());}   // 9.2 x 10^18, 
	static float nxf()	{return Float.parseFloat(nxw());}
	static double nxd() 	{return Double.parseDouble(nxw());}
	static BigInteger nxb()	{return new BigInteger(nxw());}
	static void Dprint(Object s)   {if (debug) System.out.print(s);}
	static void Dprintln(Object s) {if (debug) System.out.println(s);}
	static void Dprintln()         {if (debug) System.out.println();}
	static void Dprintf(String s, Object... args) {if (debug) System.out.printf(s, args);}
	
	static boolean debug = false;

	public static void main(String[] args) throws Exception {
		nextLine();
		int Cases = nxi();
		for (int Case=0; Case<Cases; Case++) {

			nextLine();
			int L = nxi();
			long B = nxl();
			int N = nxi();
			int C = nxi();
			int ds[] = new int[C];
			int nds[] = new int[C];
			P pds[] = new P[C+1];
			long tt = 0;
			for (int i=0; i<C; i++) {
				ds[i] = nxi();
				nds[i] = N/C + (N%C > i ? 1:0);
				tt += ds[i] * nds[i] * 2;
			}
			long bd = B/2;
			long td = 0;
			int part = 0;
			for (int i=0; i<N; i++) {
				int d = ds[i%C]; // from i to i+1
				td += d;
				nds[i%C]--;
				if (td >= bd) {
					part = (int)(td - bd);
					break;
				}
			}
			for (int i=0; i<C; i++) {
				pds[i] = new P(ds[i], nds[i]);
			}
			pds[C] = new P(part, 1);
			Arrays.sort(pds);
			for (P p: pds) {
				Dprintln(p.x + " num " + p.y);
			}
			
			int p = 0;
			long savings = 0;
			while (L > 0 && p < C+1) {
				P pp = pds[p];
				if (pp.y >= L) {
					savings += L * pp.x;
					L = 0;
				}
				else if (pp.y < L) {
					savings += pp.y * pp.x;
					L -= pp.y;
				}
				p++;
			}
			Dprintf(" tt %d sav %d\n", tt, savings);
			System.out.println("Case #" + (Case+1) + ": " + (tt - savings));
			
		} // end for each case

	} // end main
	

}

class P implements Comparable {
	int x, y;
	P(int xx, int yy) {x=xx; y=yy;}
	@Override
	public int compareTo(Object o) {
		P op = (P)o;
		return op.x - this.x;
	}
}

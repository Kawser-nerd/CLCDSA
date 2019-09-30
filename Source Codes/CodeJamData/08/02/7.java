import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class QualB {
	
	static void solve() {
		final int MAX = 110;
		int i, j, k, NA, NB, a, b, x, y, TURN;
		Go[] tr = new Go[MAX*2];
		StringTokenizer tok;
		PriorityQueue<Integer> toA = new PriorityQueue<Integer>();
		PriorityQueue<Integer> toB = new PriorityQueue<Integer>();
		Go g;
		int T = Integer.parseInt(read());
		next:
		for (int t = 1; t <= T; t++) {
			TURN = Integer.parseInt(read());
			tok = new StringTokenizer(read());
			NA = Integer.parseInt(tok.nextToken());
			NB = Integer.parseInt(tok.nextToken());
			for (i = 0; i < NA; i++) {
				tok = new StringTokenizer(read(), ": ");
				a = Integer.parseInt(tok.nextToken()) * 60 + Integer.parseInt(tok.nextToken());
				b = Integer.parseInt(tok.nextToken()) * 60 + Integer.parseInt(tok.nextToken());
				tr[i] = new Go(a, b, 0);
			}
			for (i = 0; i < NB; i++) {
				tok = new StringTokenizer(read(), ": ");
				a = Integer.parseInt(tok.nextToken()) * 60 + Integer.parseInt(tok.nextToken());
				b = Integer.parseInt(tok.nextToken()) * 60 + Integer.parseInt(tok.nextToken());
				tr[NA+i] = new Go(a, b, 1);
			}
			Arrays.sort(tr, 0, NA+NB);
			for (x = 0; x <= NA*3; x++)
				loop:
				for (y = 0; y <= NB*3; y++) {
					a = x;
					b = y;
					toA.clear();
					toB.clear();
					for (i = 0; i < NA+NB; i++) {
						g = tr[i];
						while (! toA.isEmpty() && toA.peek() <= g.a) {
							a++;
							toA.poll();
						}
						while (! toB.isEmpty() && toB.peek() <= g.a) {
							b++;
							toB.poll();
						}
						if (g.s == 0) {
							a--;
							if (a < 0)
								continue loop;
							toB.offer( g.b + TURN );
						} else {
							b--;
							if (b < 0)
								continue loop;
							toA.offer( g.b + TURN );
						}
					}
					out.println("Case #" + t + ": " + x + " " + y);
					continue next;
				}
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		in = new BufferedReader(new FileReader("B-large.in"));
		out = new PrintWriter( new FileOutputStream("B-large.out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
class Go implements Comparable<Go> {
	int a, b, s;
	public Go(int x, int y, int z) {
		a = x;
		b = y;
		s = z;
	}
	public int compareTo(Go g) {
		if (a != g.a)
			return a - g.a;
		if (b != g.b)
			return b - g.b;
		return s - g.s;
	}
}

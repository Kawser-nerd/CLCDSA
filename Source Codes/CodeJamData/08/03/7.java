import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class QualC {
	
	static final double EPS = 1e-11;
	
	static void solve() {
		int i, j, k, N;
		double f, R, t, r, g, prob, area, x, y, d, rb, ru, ul, ur, ax, ay, bx, by, cx, cy;
		StringTokenizer tok;
		int T = Integer.parseInt(read());
		for (int tt = 1; tt <= T; tt++) {
			tok = new StringTokenizer(read());
			f = Double.parseDouble(tok.nextToken());
			R = Double.parseDouble(tok.nextToken());
			t = Double.parseDouble(tok.nextToken());
			r = Double.parseDouble(tok.nextToken());
			g = Double.parseDouble(tok.nextToken());
			area = 0;
			if (g > 2*f+EPS) {
				N = (int) Math.ceil((R - t) / (g + 2*r));
				for (i = 0; i < N; i++)
					for (j = 0; j < N; j++) {
						x = (g + 2*r) * i + r;
						y = (g + 2*r) * j + r;
						d = Math.hypot(x+g, y+g);
						if (d < R-t+EPS) {
							area += (g-2*f) * (g-2*f);
							continue;
						}
						if (! fits(x+f, y+f, R-t, f))
							continue;
						double aa = area;
						rb = toRight(x+f, y+f, R-t, g, f);
						ru = toUp(rb, y+f, R-t, g, f);
						ul = toUp(x+f, y+f, R-t, g, f);
						ur = toRight(x+f, ul, R-t, g, f);
						area += (rb - (x+f)) * (ru - (y+f));
						area += (ur - (x+f)) * (ul - ru);
						area += (angle(ur, ul) - angle(rb, ru)) * (R-t-f) * (R-t-f) / 2;
						area -= area(rb, ru, ur, ru, 0, 0) + area(ur, ul, ur, ru, 0, 0);
					}
			}
			prob = 1 - 4*area / (Math.PI * R * R);
			out.println("Case #" + tt + ": " + prob);
		}
	}
	static double toRight(double x, double y, double R, double g, double f) {
		double l, u, m;
		l = x;
		u = x + g - 2*f;
		for (int i = 0; i < 200; i++) {
			m = (l + u) / 2;
			if (fits(m, y, R, f))
				l = m;
			else
				u = m;
		}
		return l;
	}
	static double toUp(double x, double y, double R, double g, double f) {
		double l, u, m;
		l = y;
		u = y + g - 2*f;
		for (int i = 0; i < 200; i++) {
			m = (l + u) / 2;
			if (fits(x, m, R, f))
				l = m;
			else
				u = m;
		}
		return l;
	}
	static boolean fits(double x, double y, double R, double f) {
		double d = Math.hypot(x, y);
		return d+f < R+EPS;
	}
	static double angle(double x, double y) {
		return Math.acos(x / Math.hypot(x, y));
	}
	static double area(double v0x, double v0y, double v1x, double v1y, double v2x, double v2y) {
		return Math.abs((v1x - v0x) * (v2y - v0y) - (v2x - v0x) * (v1y - v0y)) / 2;
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		in = new BufferedReader(new FileReader("C-large.in"));
		out = new PrintWriter( new FileOutputStream("C-large.out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}

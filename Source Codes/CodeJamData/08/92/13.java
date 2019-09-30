import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class B {
	private static final int INF = 100000000;

	public static String PNAME = "pb_old";

	private static int sx, sy;
	private static String solve() throws Exception {
		List<Integer> sizes = map(s2i, readList());
		sx = sizes.get(0);
		sy = sizes.get(1);
		List<Integer> v1 = map(s2i, readList());
		int x0 = v1.get(0);
		int y0 = v1.get(1);
		List<Integer> v2 = map(s2i, readList());
		int x1 = v2.get(0);
		int y1 = v2.get(1);

		List<Integer> v3 = map(s2i, readList());
		int x = v3.get(0);
		int y = v3.get(1);

		if (x0*y1 == x1*y0) {
			Set<Pair<Integer, Integer>> ps = new HashSet<Pair<Integer, Integer>>();
			while (x>=0 && x<sx && y>=0 && y<sy) {
				int xx = x;
				int yy = y;
				ps.add(new Pair<Integer, Integer>(x, y));
				while (xx>=0 && xx<sx && yy>=0 && yy<sy) {
					xx += x1;
					yy += y1;
					Pair<Integer, Integer> p = new Pair<Integer, Integer>(xx, yy);
					if (ps.contains(p)) break;
					if (valid(xx, yy))
						ps.add(p);
				}
				x += x0;
				y += y0;
			}
			return String.valueOf(ps.size());
		}
		long res = 0;
		while (valid(x, y)) {
			int my = y1==0?INF:(y1>0?(sy-y-1)/y1+1:y/-y1+1);
			int mx = x1==0?INF:(x1>0?(sx-x-1)/x1+1:x/-x1+1);
			res += Math.min(mx, my);
//			int xx = x;
//			int yy = y;
//			while (valid(xx, yy)) {
//				res++;
//				xx += x1;
//				yy += y1;
//			}
			x += x0;
			y += y0;
			int max = 40;
			while (!valid(x, y) && max-->0) {
				x += x1;
				y += y1;
				if (!valid(x-x0, y-y0))
					break;
			}
			if (!valid(x-x0, y-y0))
				break;
		}

		return String.valueOf(res);
	}

	private static boolean valid(int x, int y) {
		return x>=0 && x<sx && y>=0 && y<sy;
	}

	/************* Library Code starts here ************************/
	/**** Function ****/
	private static interface Function<X, Y>  {
		public Y evaluate(X x);
	}

	private static <X, Y, Z> Function<X, Z> compose(final Function<X, Y> f1, final Function<Y, Z> f2) {
		return new Function<X, Z>() {
			public Z evaluate(X x) {
				return f2.evaluate(f1.evaluate(x));
			}
		};
	}

	private static <X, Y> List<Y> map(Function<X, Y> f, Collection<X> l) {
		List<Y> ret = new ArrayList<Y>();
		for (X x : l) {
			ret.add(f.evaluate(x));
		}
		return ret;
	}

	/*** Main ***/
	public static BufferedReader br;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader(PNAME + ".in"));
		FileWriter out = new FileWriter(PNAME + ".out");
		long l = System.currentTimeMillis();
		int T = ai(br.readLine());
		for (int i=1; i<=T; i++) {
			String s = solve();
			long l2 = System.currentTimeMillis();
			System.out.print(String.format("%d/%d t:%.2f ex:%.2f", i, T , (l2-l)/1000.0, ((l2-l)/1000.0 * T) / i));
			System.out.println(" >> " + s);
			out.write("Case #" + i + ": " + s + "\n");
		}
		out.close();
		br.close();
	}
	private static String readLine() throws IOException {
		return br.readLine();
	}

	private static List<String> readList() throws IOException {
		String line = readLine();
		return Arrays.asList(line.split("\\s+"));
	}

	/**** Pair *****/
	private static class Pair<X,Y> implements Comparable<Pair<X, Y>>{
		public X x;
		public Y y;
		public Pair(X x, Y y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((x == null) ? 0 : x.hashCode());
			result = prime * result + ((y == null) ? 0 : y.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			final Pair other = (Pair) obj;
			if (x == null) {
				if (other.x != null)
					return false;
			} else if (!x.equals(other.x))
				return false;
			if (y == null) {
				if (other.y != null)
					return false;
			} else if (!y.equals(other.y))
				return false;
			return true;
		}
		public int compareTo(Pair<X, Y> o) {
			int r = tryCompare(x, o.x);
			if (r!=0) return r;
			return tryCompare(y, o.y);
		}
		private <TT> int tryCompare(TT x1, TT x2) {
			if (x1 instanceof Comparable) {
				return ((Comparable)x1).compareTo(x2);
			}
			int h1 = x1.hashCode();
			int h2 = x2.hashCode();
			return (h1<h2)?-1:((h1>h2)?1:0);
		}
	}

	/**** Counter ****/
	private static class Counter<X> extends HashMap<X, Integer> {
		public Integer get(X x) {
			if (containsKey(x))
				return super.get(x);
			return 0;
		}
		public void add(X x, int delta) {
			put(x, get(x) + delta);
		}
		public void add(X x) {
			add(x, 1);
		}
	}

	private static class DCounter<X> extends HashMap<X, Double> {
		public Double get(X x) {
			if (containsKey(x))
				return super.get(x);
			return 0.0;
		}
		public void add(X x, double delta) {
			put(x, get(x) + delta);
		}
		public void add(X x) {
			add(x, 1.0);
		}
	}

	/**** Type Casting ****/
	private static int ai(String s) {
		return Integer.valueOf(s);
	}

	private static long al(String s) {
		return Long.valueOf(s);
	}

	private static double ad(String s) {
		return Double.valueOf(s);
	}

	private static String as(int i) {
		return String.valueOf(i);
	}

	private static String as(long l) {
		return String.valueOf(l);
	}

	private static Function<String, Integer> s2i = new Function<String, Integer>(){
		public Integer evaluate(String x) {
			return ai(x);
		}
	};

	private static Function<String, Long> s2l = new Function<String, Long>(){
		public Long evaluate(String x) {
			return al(x);
		}
	};

	private static Function<String, Double> s2d = new Function<String, Double>(){
		public Double evaluate(String x) {
			return ad(x);
		}
	};

	/**** Prime Numbers ****/
	private static Integer[] shieve(int n) {
		boolean sh[] = new boolean[++n];
		for (int i = 0; i < n; i++) {
			sh[i] = true;
		}
		sh[0] = false;
		sh[1] = false;
		int found = 0;
		for (int i = 2; i < n; i++) {
			if (!sh[i]) continue;
			found++;
			for (int j=2*i; j < n; j+=i)
				sh[j] = false;
		}

		Integer[] ret = new Integer[found];
		int j=0;
		for (int i = 2; i < n; i++) {
			if (sh[i])
				ret[j++]=i;
		}
		return ret;
	}

	private static boolean isPrime(long l) {
		if (l<=2)
			return l==2;
		for (int i=2; i<l; i++) {
			if (i>l/i) break;
			if (l%i==0) return false;
		}
		return true;
	}

	private static boolean isPrime(long l, int[] shieve) {
		if (l<=2)
			return l==2;
		for (int ix = 0; ix<shieve.length; ix++) {
			int i = shieve[ix];
			if (i>l/i) break;
			if (l%i==0) return false;
		}
		return true;
	}

	/**** Coordinates ****/
	private static class Point extends Pair<Integer, Integer>{
		public Point(Integer x, Integer y) {
			super(x, y);
		}

		public Point add(Point p2) {
			return new Point(x + p2.x, y + p2.y);
		}
		public Point byK(int k) {
			return new Point(k*x, k*y);
		}

		public Point rotate90() {
			return new Point(y, -x);
		}
		public Point rotate270() {
			return new Point(-y, x);
		}
		public Point turn(int d) {
			return d>0?rotate90():rotate270();
		}
	}

	public final static Point North = new Point(0, 1);
	public final static Point South = new Point(0, -1);
	public final static Point West = new Point(1, 0);
	public final static Point East = new Point(-1, 0);

}

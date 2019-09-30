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


public class A {
	public static String PNAME = "pa";

	private static int n;
	private static class Node {
		private int val, coord;
		private List<List<Integer>> childs;
		public Node l, r;

		public Node(int val, int coord, List<List<Integer>> childs) {
			this.val = val;
			this.coord = coord;
			this.childs = childs;
			l = null;
			r = null;
		}

		public boolean complies(List<Integer> point) {
			return point.get(coord) >= val;
		}

		public Pair<List<List<Integer>>, List<List<Integer>>> split(List<List<Integer>> points) {
			List<List<Integer>>  no = new ArrayList<List<Integer>>();
			List<List<Integer>> yes = new ArrayList<List<Integer>>();
			for (List<Integer> p : points) {
				if (complies(p))
					yes.add(p);
				else
					no.add(p);
			}
			return new Pair<List<List<Integer>>, List<List<Integer>>>(no, yes);
		}

		static Node make(List<List<Integer>> points) {
			if (points.size()<4) {
				return new Node(0, -1, points);
			} else {
				int best = 10000;
				Node bestNode = null;
				Pair<List<List<Integer>>, List<List<Integer>>> xx = null;
				for (int v = 1; v<=10000; v++) {
					for (int c = 0; c<3; c++) {
						Node t = new Node(v, c, null);
						Pair<List<List<Integer>>, List<List<Integer>>>  xx1 = t.split(points);
						int d = Math.abs(points.size() - 2*xx1.x.size());
						if (d<best) {
							best = d;
							xx = xx1;
							bestNode = t;
						}
					}
				}
				bestNode.l = make(xx.x);
				bestNode.r = make(xx.y);
				return bestNode;
			}
		}

		int count(List<Integer> l0) {
			int ret = 0;
			if (coord==-1) {
				for (List<Integer> p0 : childs) {
					if (greaterEq(l0, p0))
						ret++;
				}
				return ret;
			}
			if (l0.get(coord) >= val)
				ret += l.count(l0);
			ret += r.count(l0);
			return ret;
		}

		private boolean greaterEq(List<Integer> p0, List<Integer> p1) {
			for (int i=0; i<3; i++)
				if (p0.get(i)<p1.get(i))
					return false;
			return true;
		}
	}

	private static String solve() throws Exception {
		n = ai(readLine());
		List<List<Integer>> points = new ArrayList<List<Integer>>();
		Set<Integer> as = new HashSet<Integer>();
		for (int i=0; i<n; i++) {
			List<Integer> p = map(s2i, readList());
			points.add(p);
			as.add(p.get(0));
		}
		Node t = Node.make(points);
		int max = 0;
		for (int a : as) {
			for (int b=0; b<=10000; b++) {
				int c = 10000 - a - b;
				if (c<0) break;
				List<Integer> p = Arrays.asList(a, b, c);
				int count = t.count(p);
				if (count>max)
					max = count;
			}
		}
		return as(max);
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

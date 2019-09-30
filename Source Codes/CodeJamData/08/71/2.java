import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class P1 {
	public static String PNAME = "p1";
	private static String names[];
	private static List<List<String>> ings;
	private static Map<String, Integer> nameIdx;

	private static Map<Integer, Integer> cache;

	private static String solve() throws Exception {
		int N = ai(readLine());
		names = new String[N];
		ings = new ArrayList<List<String>>();
		nameIdx = new HashMap<String, Integer>();
		for (int i = 0; i < N; i++) {
			List<String> line = readList();
			String name = line.get(0);
			names[i] = name;
			nameIdx.put(name, i);
			ArrayList<String> ings1 = new ArrayList<String>();
			for (int j = 2; j < line.size(); j++) {
				String ing = line.get(j);
				char c = ing.charAt(0);
				if (c>='A' && c<='Z')
					ings1.add(ing);
			}
			ings.add(ings1);
		}
		cache = new HashMap<Integer, Integer>();
		return as(neededBowls(0));
	}

	private static int neededBowls(int i) {
		if (cache.containsKey(i))
			return cache.get(i);

		List<Integer> costs = new ArrayList<Integer>();
		for (String s:ings.get(i)) {
			costs.add(neededBowls(nameIdx.get(s)));
		}
		Collections.sort(costs);
		int ret = 0;
		if (costs.size()==0) {
			ret = 1;
		} else if (costs.size()==1) {
			ret = Math.max(costs.get(0), 2);
		} else {
			ret = costs.size()+1;
			for (int j = 0; j < costs.size(); j++) {
				ret = Math.max(ret, costs.get(costs.size()-1-j)+j);
			}
		}

		cache.put(i, ret);
		return ret;
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
	private static List<Integer> interval(final int from, final int to, final int every) {
		final int num = (to-from) / every + 1;
		return new AbstractList<Integer>() {
			public Integer get(int index) {
				return from + index * every;
			}
			public int size() {
				return num;
			}
		};
	}
	private static List<Integer> interval(final int from, final int to) {
		return interval(from, to, 1);
	}

	private static <X, Y> List<Y> map(Function<X, Y> f, Collection<X> l) {
		List<Y> ret = new ArrayList<Y>();
		for (X x : l) {
			ret.add(f.evaluate(x));
		}
		return ret;
	}

	private static String join(String sep, Iterable<? extends Object> coll) {
		StringBuilder sb = new StringBuilder();
		boolean first = true;
		for (Object o:coll) {
			if (!first)
				sb.append(sep);
			else
				first = false;
			sb.append((o==null) ? "null" : o.toString());
		}
		return sb.toString();
	}
	/*** Main ***/
	public static BufferedReader br;
	public static void main(String[] args) throws Exception {
		br = tryOrCreate(PNAME + ".in");
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

	private static BufferedReader tryOrCreate(String string) throws IOException {
		File f = new File(string);
		if (!f.exists()) {
			FileWriter newIn = new FileWriter(string);
			newIn.write("1\n");
			newIn.close();
		}
		return new BufferedReader(new FileReader(string));
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
			if (x1==null)
				return x2==null?0:-1;
			if (x2==null)
				return 1;
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

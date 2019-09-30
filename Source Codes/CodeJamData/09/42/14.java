import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
public class B {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE =!true;
	static final boolean _SMALL = true;
	static final String _PROBLEM = "B";
	void debug(Object... os) {
//		System.err.println(deepToString(os));
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			h = sc.nextInt();
			w = sc.nextInt();
			f = sc.nextInt();
			char[][] cs = new char[h][w];
			for (int i = 0; i < h; i++) {
				cs[i] = sc.next().toCharArray();
			}
			F init = new F(0, 0, cs, 0);
			que = new PriorityQueue<F>();
			map = new HashMap<F, Integer>();
			que.offer(init);
			map.put(init, 0);
			int res = -1;
			while (!que.isEmpty()) {
				F f = que.poll();
				if (f.x == h - 1) {
					res = f.step;
					break;
				}
				f.addNexts();
			}
			if (res == -1) {
				System.out.println("No");
			} else {
				System.out.println("Yes " + res);
			}
		}
	}
	HashMap<F, Integer> map;
	PriorityQueue<F> que;
	int w, h, f;
	class F implements Comparable<F> {
		final int step;
		final int x, y;
		char[][] cs;
		F(int x, int y, char[][] cs, int step) {
			this.x = x;
			this.y = y;
			this.cs = new char[h][];
			for (int i = 0; i < h; i++)
				this.cs[i] = cs[i].clone();
// this.cs=cs;
			this.step = step;
		}
		void addNexts() {
			ArrayList<F> list = new ArrayList<F>();
			if (0 < y && x < h - 1) {
				if (cs[x][y - 1] != '#' && cs[x + 1][y - 1] == '#') {
					cs[x + 1][y - 1] = '.';
					list.add(new F(x, y, cs, step + 1));
					cs[x+1][y-1]='#';
				}
			}
			if (y < w - 1 && x < h - 1) {
				if (cs[x][y + 1] != '#' && cs[x + 1][y + 1] == '#') {
					cs[x + 1][y + 1] = '.';
					list.add(new F(x, y, cs, step + 1));
					cs[x+1][y+1]='#';
				}
			}
			if (y > 0) {
				int nx = x, ny = y - 1;
				if (cs[nx][ny] != '#') {
					while (nx < h && cs[nx][ny] != '#') {
						nx++;
					}
					nx--;
					if (nx - x <= f) {
						list.add(new F(nx, ny, cs, step));
					}
				}
			}
			if (y < w - 1) {
				int nx = x, ny = y + 1;
				if (cs[nx][ny] != '#') {
					while (nx < h && cs[nx][ny] != '#') {
						nx++;
					}
					nx--;
					if (nx - x <= f) {
						list.add(new F(nx, ny, cs, step));
					}
				}
			}

// debug(list);
			for (F nf : list) {
//				debug(nf.cs);
				if (map.containsKey(nf) && nf.step >= map.get(nf))
					continue;
				map.put(nf, nf.step);
				que.offer(nf);
			}
		}
		@Override
		public int compareTo(F o) {
			return step - o.step;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
//			result = prime * result + Arrays.hashCode(cs);
			result = prime * result + x;
			result = prime * result + y;
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
			F other = (F) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			for(int i=0;i<cs.length;i++){
				if(!Arrays.equals(cs[i], other.cs[i]))return false;
			}
//			if (!Arrays.equals(cs, other.cs))
//				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		private B getOuterType() {
			return B.this;
		}

	}

	boolean in(long from, long n, long to) {
		return from <= n && n < to;
	}

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new B().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new B().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new B().run();
			}
		} else
			new B().run();
	}
	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}
	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}

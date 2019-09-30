import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Data {
	private String[] expr = new String[20000];
	public List<Integer> l = new ArrayList<Integer>();
	
	public void add(final int x, final String s) {
		int y = x + 10000;
		if (expr[y] == null) {
			l.add(x);
		}
		if (expr[y] == null || expr[y].compareTo(s) > 0) {
			expr[y] = s;
//			System.out.println(s + '=' + x);
		}
	}
	
	public String get(final int x) {
		return expr[x + 10000];
	}
	
	public void clear() {
		Arrays.fill(expr, null);
		l.clear();
	}
}

class Neigh {
	String suf;
	int dif;
	int j2;
	int k2;
}

public class Square {
	private static final int[][] DIR = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		for (int i = 0; i < t; ++i) {
			System.out.println(i);
			final int w = sc.nextInt();
			final int q = sc.nextInt();
			sc.nextLine();
			final String[] sq = new String[w];
			for (int j = 0; j < w; ++j) {
				sq[j] = sc.nextLine();
			}
			final String[] str = sc.nextLine().split(" ");
			if (str.length != q) {
				throw new RuntimeException();
			}
			final int[] num = new int[q];
			for (int j = 0; j < q; ++j) {
				num[j] = Integer.parseInt(str[j]);
			}
			final String[] expr = new String[q];
			int n = q;
			Data[][] d1 = new Data[w][w];
			Data[][] d2 = new Data[w][w];
			for (int j = 0; j < w; ++j) {
				for (int k = 0; k < w; ++k) {
					final char c = sq[j].charAt(k);
					if (Character.isDigit(c)) {
						d1[j][k] = new Data();
						d2[j][k] = new Data();
						d1[j][k].add(c - '0', String.valueOf(c));
					}
				}
			}
			
			List[][] neigh = new List[w][w];
			for (int j = 0; j < w; ++j) {
				for (int k = 0; k < w; ++k) {
					final char c = sq[j].charAt(k);
					if (Character.isDigit(c)) {
						neigh[j][k] = new ArrayList<Neigh>();
						for (int[] dir1 : DIR) {
							int j1 = j + dir1[0];
							int k1 = k + dir1[1];
							if (j1 >= 0 && k1 >= 0 && j1 < w && k1 < w) {
								final char c1 = sq[j1].charAt(k1);
								int dif = (c1 == '+' ? 1 : -1) * (c - '0');
								for (int[] dir2 : DIR) {
									int j2 = j1 + dir2[0];
									int k2 = k1 + dir2[1];
									if (j2 >= 0 && k2 >= 0 && j2 < w && k2 < w) {
										Neigh n1 = new Neigh();
										n1.suf = c1 + "" + c;
										n1.dif = dif;
										n1.j2 = j2;
										n1.k2 = k2;
										neigh[j][k].add(n1);
									}
								}
							}
						}
					}
				}
			}
			
			System.out.println("n=" + n);
			while (true) {
				for (int x = 0; x < q; ++x) {
					if (expr[x] == null) {
						String s = "a";
						for (int j = 0; j < w; ++j) {
							for (int k = 0; k < w; ++k) {
								if (d1[j][k] != null) {
									String e = d1[j][k].get(num[x]);
									if (e != null && e.compareTo(s) < 0) {
										s = e;
									}
								}
							}
						}
						if (!"a".equals(s)) {
							expr[x] = s;
							--n;
							System.out.println("n=" + n);
						}
					}
				}
				if (n == 0) {
					break;
				}
				for (int j = 0; j < w; ++j) {
					for (int k = 0; k < w; ++k) {
						if (neigh[j][k] != null) {
							for (Object o : neigh[j][k]) {
								Neigh n1 = (Neigh) o;
								for (int p : d1[n1.j2][n1.k2].l) {
									d2[j][k].add(p + n1.dif, d1[n1.j2][n1.k2].get(p) + n1.suf);
								}
							}
						}
					}
				}
				Data[][] dt = d1;
				d1 = d2;
				d2 = dt;
				for (int j = 0; j < w; ++j) {
					for (int k = 0; k < w; ++k) {
						final char c = sq[j].charAt(k);
						if (d2[j][k] != null) {
							d2[j][k].clear();
						}
					}
				}
			}
			pw.println("Case #" + (i + 1) + ":");
			for (String s : expr) {
				pw.println(s);
			}
		}
		pw.close();
	}
}

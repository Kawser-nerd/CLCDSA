import java.awt.Point;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class Sokoban {
	static String[][][] shapes={
			{{"x"}},
			{{"xx"}},
			{{"xxx"}, {"xx", "x"}},
			{{"xxxx"}, {"xxx", "x"}, {"xxx", " x"}, {"xx", "xx"}, {"xx", " xx"}},
			{{"xxxxx"}, {"xxxx", "x"}, {"xxxx", " x"}, {"xxx", "xx"}, {"xxx", "x x"}, {"xxx", "  xx"}, {" x", "xxx", " x"},
				{"xx", " xx", "  x"}, {"xxx", "x", "x"}, {" x", "xxx", "  x"}, {"xxx", " x", " x"}, {"xx", " x", " xx"}}
	};
	
	static char[][] copy(char[][] m) {
		final int r = m.length;
		final int c = m[0].length;
		char[][] a = new char[r][c];
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				a[i][j] = m[i][j];
			}
		}
		return a;
	}
	
	static char[][] rot(char[][] m) {
		final int n = m.length;
		char[][] a = new char[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = m[j][n - 1 - i];
			}
		}
		return a;
	}
	
	static char[][] mir(char[][] m) {
		final int n = m.length;
		char[][] a = new char[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = m[j][i];
			}
		}
		return a;
	}
	
	static String str(char[][] m) {
		final int n = m.length;
		final StringBuilder sb = new StringBuilder(n * n);
		for (int i = 0; i < n; ++i) {
			sb.append(m[i]);
		}
		return sb.toString();
	}
	
	static char[][] mat(String s, int b) {
		char[][] a = new char[b][b];
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				a[i][j] = s.charAt(i * b + j);
			}
		}
		return a;
	}
	
	static void apply(char[][]m, char[][]a, char ch, int r, int c) {
		int n = a.length;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == 'x') {
					m[r + i][c + j] = ch;
				}
			}
		}
	}
	
	static char[][] search(char[][] m, int b, char c1, char c2, Point p) {
		int r = 100;
		int c = 100;
		for (int i = 0; i < m.length; ++i) {
			for (int j = 0; j < m[0].length; ++j) {
				if (m[i][j] == c1 || m[i][j] == c2) {
					if (i < r) r = i;
					if (j < c) c = j;
				}
			}
		}
		if (p != null) {
			p.x = r;
			p.y = c;
		}
		char[][] a = new char[b][b];
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				if (r + i < m.length && c + j < m[0].length && (m[r + i][c + j] == c1 || m[r + i][c + j] == c2)) {
					a[i][j] = 'x';
				} else {
					a[i][j] = ' ';
				}
			}
		}
		return a;
	}
	
	static List<List<String>> shape2 = new ArrayList<List<String>>();
	
	static void precalc() {
		shape2.add(null);
		for (int b = 1; b <= 5; ++b) {
			char[][] m = new char[b][b];
			Set<String> s = new HashSet<String>();
			for (String[] sh : shapes[b - 1]) {
				for (int i = 0; i < b; ++i) {
					for (int j = 0; j < b; ++j) {
						m[i][j] = ' ';
					}
				}
				for (int i = 0; i < sh.length; ++i) {
					for (int j = 0; j < sh[i].length(); ++j) {
						m[i][j] = sh[i].charAt(j);
					}
				}
				for (int i = 0; i < 4; ++i) {
					s.add(str(m));
					s.add(str(search(mir(m), b, 'x', 'x', null)));
					m = search(rot(m), b, 'x', 'x', null);
				}
			}
			shape2.add(new ArrayList<String>(s));
		}
	}
	
	static class Data {
		int r;
		int c;
		int s;
	}
	
	public static void main(final String... args) throws IOException {
		precalc();
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		for (int i = 0; i < t; ++i) {
			final int r = sc.nextInt();
			final int c = sc.nextInt();
			sc.nextLine();
			final char[][] m = new char[r][];
			for (int j = 0; j < r; ++j) {
				m[j] = sc.nextLine().toCharArray();
			}
			char[][] a = search(m, 5, 'o', 'w', null);
			int b = 0;
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					if (a[j][k] == 'x') ++b;
				}
			}
			List<String> shp = shape2.get(b);
			Point orig = new Point();
			a = search(m, b, 'o', 'w', orig);
			int sorig = shp.indexOf(str(a));
			
			Point goal = new Point();
			a = search(m, b, 'x', 'w', goal);
			int sgoal = shp.indexOf(str(a));
			if (sgoal < 0) {
				for (char[] cc : m) {
					System.out.println(new String(cc));
				}
			}
			
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					if (m[j][k] == 'w' || m[j][k] == 'o' || m[j][k] == 'x') {
						m[j][k] = '.';
					}
				}
			}
			
			int ns = shp.size();
			final int[][][] g = new int[r][c][ns];
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					Arrays.fill(g[j][k], -1);
				}
			}
			g[orig.x][orig.y][sorig] = 0;
			if (g[goal.x][goal.y][sgoal] != 0) {
				PriorityQueue<Data> q = new PriorityQueue<Data>(10, new Comparator<Data>() {
					@Override
					public int compare(Data o1, Data o2) {
						return g[o1.r][o1.c][o1.s] - g[o2.r][o2.c][o2.s];
					}
				});
				Data d = new Data();
				d.r = orig.x;
				d.c = orig.y;
				d.s = sorig;
				q.add(d);
				while (!q.isEmpty()) {
					if (g[goal.x][goal.y][sgoal] >= 0) {
						break;
					}
					d = q.poll();
					apply(m, mat(shp.get(d.s), b), 'o', d.r, d.c);
					List<char[][]> l = new ArrayList<char[][]>();
					for (int j = 0; j < r; ++j) {
						for (int k = 0; k < c; ++k) {
							if (m[j][k] == 'o') {
								if (j > 0 && j < r - 1 && m[j-1][k]=='.' && m[j+1][k]=='.') {
									char[][]m1 = copy(m);
									m1[j][k]='.';
									m1[j-1][k]='o';
									l.add(m1);
									m1 = copy(m);
									m1[j][k]='.';
									m1[j+1][k]='o';
									l.add(m1);
								}
								if (k > 0 && k < c - 1 && m[j][k-1]=='.' && m[j][k+1]=='.') {
									char[][]m1 = copy(m);
									m1[j][k]='.';
									m1[j][k-1]='o';
									l.add(m1);
									m1 = copy(m);
									m1[j][k]='.';
									m1[j][k+1]='o';
									l.add(m1);
								}
							}
						}
					}
					for(char[][]m1 : l) {
						Point p = new Point();
						a = search(m1, b, 'o', 'o', p);
						int x = shp.indexOf(str(a));
						if (x >= 0 && g[p.x][p.y][x] < 0) {
							g[p.x][p.y][x] = g[d.r][d.c][d.s] + 1;
							Data d1 = new Data();
							d1.r = p.x;
							d1.c = p.y;
							d1.s = x;
							q.add(d1);
						}
					}
					for(char[][]m2 : l) {
						Point p = new Point();
						a = search(m2, b, 'o', 'o', p);
						int x = shp.indexOf(str(a));
						if (x >= 0 && g[p.x][p.y][x] < 0) {
							g[p.x][p.y][x] = g[d.r][d.c][d.s] + 1;
							Data d1 = new Data();
							d1.r = p.x;
							d1.c = p.y;
							d1.s = x;
							q.add(d1);
						}
						
						for (int j = 0; j < r; ++j) {
							for (int k = 0; k < c; ++k) {
								if (m2[j][k] == 'o') {
									if (j > 0 && j < r - 1 && m2[j-1][k]=='.' && m2[j+1][k]=='.') {
										char[][]m1 = copy(m2);
										m1[j][k]='.';
										m1[j-1][k]='o';
										
										a = search(m1, b, 'o', 'o', p);
										x = shp.indexOf(str(a));
										if (x >= 0 && g[p.x][p.y][x] < 0) {
											g[p.x][p.y][x] = g[d.r][d.c][d.s] + 2;
											Data d1 = new Data();
											d1.r = p.x;
											d1.c = p.y;
											d1.s = x;
											q.add(d1);
										}
										
										m1[j-1][k]='.';
										m1[j+1][k]='o';
										
										a = search(m1, b, 'o', 'o', p);
										x = shp.indexOf(str(a));
										if (x >= 0 && g[p.x][p.y][x] < 0) {
											g[p.x][p.y][x] = g[d.r][d.c][d.s] + 2;
											Data d1 = new Data();
											d1.r = p.x;
											d1.c = p.y;
											d1.s = x;
											q.add(d1);
										}
										
									}
									if (k > 0 && k < c - 1 && m2[j][k-1]=='.' && m2[j][k+1]=='.') {
										char[][]m1 = copy(m2);
										m1[j][k]='.';
										m1[j][k-1]='o';
										
										a = search(m1, b, 'o', 'o', p);
										x = shp.indexOf(str(a));
										if (x >= 0 && g[p.x][p.y][x] < 0) {
											g[p.x][p.y][x] = g[d.r][d.c][d.s] + 2;
											Data d1 = new Data();
											d1.r = p.x;
											d1.c = p.y;
											d1.s = x;
											q.add(d1);
										}
										
										m1[j][k-1]='.';
										m1[j][k+1]='o';
										
										a = search(m1, b, 'o', 'o', p);
										x = shp.indexOf(str(a));
										if (x >= 0 && g[p.x][p.y][x] < 0) {
											g[p.x][p.y][x] = g[d.r][d.c][d.s] + 2;
											Data d1 = new Data();
											d1.r = p.x;
											d1.c = p.y;
											d1.s = x;
											q.add(d1);
										}
									}
								}
							}
						}
						
						
					}
					
					apply(m, mat(shp.get(d.s), b), '.', d.r, d.c);
				}
			}
			pw.println("Case #" + (i + 1) + ": " + g[goal.x][goal.y][sgoal]);
		}
		pw.close();
	}
}

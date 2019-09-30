import java.io.FileInputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    class E {
        int s;
        int t;
        boolean u;

        public E(int s, int t) {
            this.s = s;
            this.t = t;
        }
    }

    class R {
        int s;
        int t;
        int d;

        public R(int s, int t, int d) {
            this.s = s;
            this.t = t;
            this.d = d;
        }
    }

    ArrayList<E> e[];

    int dist(int a, int b, int n) {
        return Math.min(Math.abs(a - b), n - Math.abs(a - b));
    }

    boolean bfs(int s, int t) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.addLast(s);
        int n = e.length;
        boolean[] vis = new boolean[n];
        E[] from = new E[n];
        vis[s] = true;
        while (!q.isEmpty()) {
            int x = q.pollFirst();
            for (E ed : e[x]) {
                if (!ed.u && !vis[ed.t]) {
                    from[ed.t] = ed;
                    q.addLast(ed.t);
                    vis[ed.t] = true;
                }
            }
        }
        if (!vis[t]) {
            return false;
        }
        int x = t;
        while (x != s) {
from[x].u = true;
            x = from[x].s;
        }
return true;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();

        int[] vn = new int[2 * (r + c)];
        for (int i = 0; i < c; i++) {
            vn[i] = i;
        }
        for (int i = 0; i < r; i++) {
            vn[c + i] = (r + 1) * c + c * r + i;
        }
        for (int i = 0; i < c; i++) {
            vn[c + r + i] = r * c + c - 1 - i;
        }
        for (int i = 0; i < r; i++) {
            vn[c + r + c + i] = (r + 1) * c + r - 1 - i;
        }

        e = new ArrayList[(r + 1) * c + (c + 1) * r + r * c * 2];
        for (int i = 0; i < e.length; i++) {
            e[i] = new ArrayList<>();
        }

        int d = (r + 1) * c + r * (c + 1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i + j) % 2 == 0) {
                    int s = i * c + j;
                    int t = d + 2 * (i * c + j);
                    e[s].add(new E(s, t));
                    e[s].add(new E(s, t + 1));
                    e[s + c].add(new E(s + c, t));
                    e[s + c].add(new E(s + c, t + 1));
                    int f = (r + 1) * c + j * r + i;
                    e[t].add(new E(t, f));
                    e[t + 1].add(new E(t + 1, f + r));
                } else {
                    int s = (r + 1) * c + j * r + i;
                    int t = d + 2 * (i * c + j);
                    e[s].add(new E(s, t));
                    e[s].add(new E(s, t + 1));
                    e[s + r].add(new E(s + r, t));
                    e[s + r].add(new E(s + r, t + 1));
                    int f = i * c + j;
                    e[t].add(new E(t, f));
                    e[t + 1].add(new E(t + 1, f + c));
                }
            }
        }

        int[] deg = new int[e.length];
        for (int i = 0; i < e.length; i++) {
            for (E ed : e[i]) {
                deg[ed.s]++;
            }
        }

        int[][] v = new int[r + c][2];

        R[] prs = new R[r + c];
        int[] st = new int[r + c];
        int[] fn = new int[r + c];
        for (int i = 0; i < r + c; i++) {
            v[i][0] = in.nextInt() - 1;
            v[i][1] = in.nextInt() - 1;
            if (deg[vn[v[i][0]]] > 0) {
                st[i] = vn[v[i][0]];
                fn[i] = vn[v[i][1]];
            } else {
                st[i] = vn[v[i][1]];
                fn[i] = vn[v[i][0]];
            }
            prs[i] = new R(st[i], fn[i], dist(v[i][0], v[i][1], 2 * (r + c)));
        }

        Arrays.sort(prs, (x, y) -> x.d - y.d);
        boolean allOk = true;
        for (R qq : prs) {
if (!bfs(qq.s, qq.t)) {
                allOk = false;
            }
        }


        out.println("Case #" + testNumber + ":");
        if (allOk) {
            char[][] f = new char[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    boolean bk = false;
                    if ((i + j) % 2 == 0) {
                        for (E ed : e[i * c + j]) {
                            if (ed.u && (ed.t - d) % 2 == 1) {
                                bk = true;
                            }
                        }
                        for (E ed : e[(i + 1) * c + j]) {
                            if (ed.u && (ed.t - d) % 2 == 0) {
                                bk = true;
                            }
                        }
                    } else {
                        for (E ed : e[(r + 1) * c + j * r + i]) {
                            if (ed.u && (ed.t - d) % 2 == 1) {
                                bk = true;
                            }
                        }
                        for (E ed : e[(r + 1) * c + (j + 1) * r + i]) {
                            if (ed.u && (ed.t - d) % 2 == 0) {
                                bk = true;
                            }
                        }
                    }
                    if (bk) {
                        f[i][j] = '\\';
                    } else {
                        f[i][j] = '/';
                    }
                }
            }
            for (int i = 0; i < r; i++) {
                StringBuilder s = new StringBuilder();
                for (int j = 0; j < c; j++) {
                    s.append(f[i][j]);
                }
                out.println(s);
            }
        } else {
            out.println("IMPOSSIBLE");
        }
    }

}


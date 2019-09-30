package round3;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class B {
	static int mod = 1000003;
	static int n, m;
	static class Grana {
		int a, b;
		public Grana(int i1, int j1, int i2, int j2) {
			if (i1 < 0)
				i1 += n;
			if (j1 < 0)
				j1 += m;
			if (i2 < 0)
				i2 += n;
			if (j2 < 0)
				j2 += m;

			if (i1 >= n)
				i1 -= n;
			if (j1 >= m)
				j1 -= m;
			if (i2 >= n)
				i2 -= n;
			if (j2 >= m)
				j2 -= m;

			a = i1 * m + j1;
			b = i2 * m + j2;
		}
		public Grana(Grana g) {
			this.a = g.b;
			this.b = g.a;
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int tt = in.nextInt();
		for (int ttt = 1; ttt <= tt; ttt++) {
			n = in.nextInt();
			m = in.nextInt();
			ArrayList<Grana> g = new ArrayList<B.Grana>();
			ArrayList<ArrayList<Grana>> gg = new ArrayList<ArrayList<Grana>>();
			for (int i = 0; i < n * m; i++)
				gg.add(new ArrayList<B.Grana>());
			for (int i = 0; i < n; i++) {
				String s = in.next();
				for (int j = 0; j < m; j++) {
					switch (s.charAt(j)) {
						case '|':
							g.add(new Grana(i - 1, j, i + 1, j));
							break;
						case '-':
							g.add(new Grana(i, j - 1, i, j + 1));
							break;
						case '/':
							g.add(new Grana(i + 1, j - 1, i - 1, j + 1));
							break;
						case '\\':
							g.add(new Grana(i - 1, j - 1, i + 1, j + 1));
							break;
						default:
							throw new RuntimeException("" + s.charAt(j));
					}
					Grana tg = g.get(g.size() - 1);
					gg.get(tg.a).add(tg);
					gg.get(tg.b).add(new Grana(tg));
				}
			}

			int[] u = new int[n * m];
			for (int i = 0; i < n * m; i++)
				u[i] = 0;
			for (Grana gr : g) {
				u[gr.a]++;
				u[gr.b]++;
			}

			boolean imaNula = false;
			boolean[] gotov = new boolean[n * m];
			int res = 0;
			LinkedList<Integer> listovi = new LinkedList<Integer>();
			for (int i = 0; i < n * m; i++)
				if (u[i] == 0)
					imaNula = true;
				else if (u[i] == 1)
					listovi.add(i);
			if (!imaNula) {
				while (listovi.size() > 0) {
					int i = listovi.poll();
					gotov[i] = true;
					int j = 0;
					while ((j < gg.get(i).size()) && gotov[gg.get(i).get(j).b])
						j++;
					if (j < gg.get(i).size()) {
						int other = gg.get(i).get(j).b;
						u[other]--;
						if (u[other] == 1)
							listovi.add(other);
						if (u[other] == 0)
							imaNula = true;
					}
				}
				if (!imaNula) {
					res = 1;
					for (int i = 0; i < n * m; i++)
						if (!gotov[i]) {
							res = (2 * res) % mod;
							int t = i;
							while (true) {
								gotov[t] = true;
								int j = 0;
								while ((j < gg.get(t).size())
										&& gotov[gg.get(t).get(j).b])
									j++;
								if (j < gg.get(t).size())
									t = gg.get(t).get(j).b;
								else
									break;
							}
						}
				}
			}

			out.printf("Case #%d: %d", ttt, res);
			out.println();
		}
		out.flush();
		out.close();
		in.close();
	}
}

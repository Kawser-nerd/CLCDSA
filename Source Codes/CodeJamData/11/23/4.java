package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Kittens {
	static int n;

	static class Zid {
		int s, e;
		Zid(int s, int e) {
			s--;
			e--;
			if (s > e) {
				int pom = s;
				s = e;
				e = pom;
			}
			if (2 * (e - s) > n) {
				this.e = s;
				this.s = e;
			} else {
				this.e = e;
				this.s = s;
			}
		}

		int udaljenost() {
			return (e + n - s) % n;
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("kittens.in"));
		PrintWriter out = new PrintWriter(new File("kittens.out"));
		int tt = in.nextInt();
		for (int t = 1; t <= tt; t++) {
			// System.out.println();
			n = in.nextInt();
			int m = in.nextInt();
			int[] sss = new int[m];
			int[] eee = new int[m];
			for (int i = 0; i < m; i++)
				sss[i] = in.nextInt();
			for (int i = 0; i < m; i++)
				eee[i] = in.nextInt();

			Zid[] z = new Zid[m];
			for (int i = 0; i < m; i++)
				z[i] = new Zid(sss[i], eee[i]);

			int[] sledeci = new int[n];
			for (int i = 0; i < n - 1; i++)
				sledeci[i] = i + 1;
			sledeci[n - 1] = 0;

			int res = n;
			int[] boja = new int[n];

			Arrays.sort(z, new Comparator<Zid>() {
				@Override
				public int compare(Zid o1, Zid o2) {
					return o1.udaljenost() - o2.udaljenost();
				}
			});

			ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();

			for (int i = 0; i < m; i++) {
				int s = z[i].s;
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(s);
				while (s != z[i].e) {
					s = sledeci[s];
					list.add(s);
				}
				res = Math.min(res, list.size());
				g.add(list);
				sledeci[z[i].s] = z[i].e;
			}

			int pommm = z[m - 1].e;
			ArrayList<Integer> listtt = new ArrayList<Integer>();
			listtt.add(pommm);
			pommm = sledeci[pommm];
			while (pommm != z[m - 1].e) {
				listtt.add(pommm);
				pommm = sledeci[pommm];
			}
			g.add(listtt);
			res = Math.min(res, listtt.size());

			for (int i = 0; i < n; i++)
				boja[i] = -1;
			boja[listtt.get(0)] = 0;
			for (int i = 1; i < listtt.size(); i++)
				boja[listtt.get(i)] = (boja[listtt.get(i - 1)] + 1) % res;
			if (boja[listtt.get(listtt.size() - 1)] == boja[listtt.get(0)])
				boja[listtt.get(listtt.size() - 1)] = (boja[listtt.get(0)] + 1)
						% res;
			if (boja[listtt.get(listtt.size() - 1)] == boja[listtt.get(listtt
					.size() - 2)])
				boja[listtt.get(listtt.size() - 1)] = (boja[listtt.get(listtt
						.size() - 2)] + 1) % res;
			for (int i = 0; i < res; i++) {
				boolean ok = false;
				for (int j = 0; j < listtt.size(); j++)
					if (boja[listtt.get(j)] == i)
						ok = true;
				if (!ok) {
					System.err.println("?????");
					// System.out.println(n + " " + m + " " + t);
					// for (int aa = 0; aa < m; aa++)
					// System.out.println(z[aa].s + " " + z[aa].e);
				}
			}

			for (int gt = g.size() - 2; gt >= 0; gt--) {
				ArrayList<Integer> l = g.get(gt);
				if (boja[l.get(0)] == -1)
					System.err.println("??");
				if (boja[l.get(l.size() - 1)] == -1)
					System.err.println("???");

				ArrayList<Integer> slobodneBoje = new ArrayList<Integer>();
				for (int i = 0; i < res; i++)
					if (i != boja[l.get(0)] && i != boja[l.get(l.size() - 1)])
						slobodneBoje.add(i);

				for (int x = l.size() - 2; x > 0; x--)
					if (slobodneBoje.size() > 0) {
						boja[l.get(x)] = slobodneBoje
								.get(slobodneBoje.size() - 1);
						slobodneBoje.remove(slobodneBoje.size() - 1);
					} else
						boja[l.get(x)] = (boja[l.get(x + 1)] + 1) % res;
				if (boja[l.get(1)] == boja[l.get(0)])
					boja[l.get(1)] = (boja[l.get(0)] + 1) % res;
				if (boja[l.get(1)] == boja[l.get(2)])
					boja[l.get(1)] = (boja[l.get(2)] + 1) % res;

				for (int i = 0; i < res; i++) {
					boolean ok = false;
					for (int j = 0; j < l.size(); j++)
						if (boja[l.get(j)] == i)
							ok = true;
					if (!ok)
						System.err.println("????");
				}
			}

			out.println("Case #" + t + ": " + res);
			for (int i = 0; i < n - 1; i++)
				out.print((boja[i] + 1) + " ");
			out.print(boja[n - 1] + 1);
			out.println();
		}
		out.flush();
		out.close();
	}
}

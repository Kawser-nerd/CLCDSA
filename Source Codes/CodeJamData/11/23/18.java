import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class third {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	};

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	};

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	};

	long nextLong() throws IOException {
		return Long.parseLong(next());
	};

	int rooms[][];
	int kilk[];
	int min;
	int wht[];
	int pos[];
	int par[];
	int t;
	int st[];
	int en[];
	int res[];
	int tek[];
	int stek[];
	int tl, lp, minroom;
	int resul;

	int check() {
		int wht[] = new int[minroom];
		for (int i = 0; i < lp; i++)
		{
			int buv[]=new int[minroom];
			for (int j = 0; j < kilk[i]; j++)
				if (buv[tek[rooms[i][j]]]==0)
				{
					wht[tek[rooms[i][j]]]++;
					buv[tek[rooms[i][j]]]=1;
				}
		};
		int kilk = 0;
		for (int i = 0; i < minroom - 1; i++)
			if ((wht[i] == 0) && (wht[i + 1] != 0))
				return -1;
		for (int i = 0; i < minroom; i++)
			if ((wht[i] < lp) && (wht[i] != 0))
				return -1;
		for (int i = 0; i < minroom; i++)
			if (wht[i] != 0)
				kilk++;
		return kilk;
	}

	int solve(int num, int wht) {
		if (num == n) {
			int tpl = check();
			if (tpl > resul) {
				res = tek.clone();
				resul = tpl;
			}
			return resul;
		}
		int resul = 0;
		for (int t = 0; t < minroom; t++) {
			int i = (t + wht) % minroom;
			tek[num] = i;
			resul = Math.max(solve(num + 1, (i + 1) % minroom), resul);
			if (resul == minroom)
				return resul;
		}
		return resul;
	}

	int n, m;

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		st = new int[m];
		en = new int[m];
		t = 0;
		pos = new int[n];
		par = new int[m + 20];
		rooms = new int[n][n];
		kilk = new int[n];
		tek = new int[n];
		stek = new int[n];
		st = new int[n];
		wht = new int[n];
		en = new int[n];
		tl = 0;
		for (int i = 0; i < m; i++) {
			st[i] = nextInt();
		}
		for (int j = 0; j < m; j++) {
			en[j] = nextInt();
		}
		st[m] = 1;
		en[m] = n;
		for (int i = 0; i <= m; i++) {
			int a = Math.min(st[i], en[i]) - 1;
			int b = Math.max(st[i], en[i]) - 1;
			t++;
			par[t] = pos[b];
			wht[t] = a;
			pos[b] = t;
			int v = t;
			while ((par[v] > 0) && (wht[v] < wht[par[v]])) {
				int k = wht[par[v]];
				wht[par[v]] = wht[v];
				wht[v] = k;
				v = par[v];
			}
		}
		lp = 0;
		minroom = 1000;

		for (int i = 0; i < n; i++) {
			stek[tl] = i;
			tl++;
			int v = pos[i];
			while ((tl > 1) && (v > 0)) {
				if (stek[tl - 2] != wht[v]) {
					kilk[lp] = 2;
					rooms[lp][0] = i;
					rooms[lp][1] = wht[v];
					while (stek[tl - 2] != wht[v]) {
						rooms[lp][kilk[lp]] = stek[tl - 2];
						kilk[lp]++;
						stek[tl - 2] = stek[tl - 1];
						tl--;
					}
					minroom = Math.min(minroom, kilk[lp]);
					lp++;
				}
				v = par[v];
			}
		}
		resul = -1;
		out.println(solve(0, 0));
		for (int i = 0; i < n - 1; i++)
			out.print((res[i] + 1) + " ");
		out.println(res[n - 1]+1);
	};

	void run() throws IOException {
		Locale.setDefault(Locale.US);
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new third().run();
	}

}

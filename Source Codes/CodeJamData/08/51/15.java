import java.util.*;
import java.text.*;
import java.io.*;
import java.text.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new InputStreamReader(System.in));
		br = new BufferedReader(new FileReader(inpFile));
		st = new StreamTokenizer(br);
		// out = new PrintWriter(System.out);
		out = new PrintWriter(outFile);
		new Thread(new Main()).start();
	}

	static String taskID = "2";

	static String inpFile = taskID + ".in";

	static String outFile = taskID + ".out";

	static BufferedReader br;

	static PrintWriter out;

	static StreamTokenizer st;

	static void nt() {
		try {
			st.nextToken();
		} catch (IOException ex) {
		}
	}

	int ni() {
		nt();
		return (int) st.nval;
	}

	long nl() {
		nt();
		return (long) st.nval;
	}

	String ns() {
		nt();
		return st.sval;
	}

	double nd() {
		nt();
		return st.nval;
	}

	String nline() {
		try {
			return br.readLine();
		} catch (IOException ex) {
			return null;
		}
	}

	int[] di = new int[] { -1, 0, 1, 0 };
	int[] dj = new int[] { 0, 1, 0, -1 };

	int MAX = 6100;

	long comp() {
		int n = ni();
		// boolean[][][] map = new boolean[MAX][MAX][4];
		BitSet[] mapl = new BitSet[MAX], mapr = new BitSet[MAX], mapu = new BitSet[MAX], mapd = new BitSet[MAX];
		for (int i = 0; i < MAX; i++) {
			mapl[i] = new BitSet(MAX);
			mapr[i] = new BitSet(MAX);
			mapu[i] = new BitSet(MAX);
			mapd[i] = new BitSet(MAX);
		}
		int ci = MAX / 2;
		int cj = MAX / 2;
		int dir = 0;
		int mini = ci;
		int minj = cj;
		int maxi = ci;
		int maxj = cj;
		long s = 0;
		for (int i = 0; i < n; i++) {
			char[] p = ns().toCharArray();
			int cnt = ni();
			for (int j = 0; j < cnt; j++) {
				for (int v = 0; v < p.length; v++) {
					if (p[v] == 'R')
						dir = (dir + 1) % 4;
					else if (p[v] == 'L')
						dir = (dir + 3) % 4;
					else if (p[v] == 'F') {
						if (dir == 0) {
							mapl[cj].set(ci - 1);
							mapr[cj - 1].set(ci - 1);
						} else if (dir == 1) {
							mapd[ci - 1].set(cj);
							mapu[ci].set(cj);
							s += ci;
						} else if (dir == 2) {
							mapr[cj - 1].set(ci);
							mapl[cj].set(ci);
						} else {
							mapd[ci - 1].set(cj - 1);
							mapu[ci].set(cj - 1);
							s -= ci;
						}
						ci += di[dir];
						cj += dj[dir];
						mini = min(mini, ci);
						minj = min(minj, cj);
						maxi = max(maxi, ci);
						maxj = max(maxj, cj);
					}
				}
			}
		}
		s = abs(s);
		BitSet[] pl = new BitSet[MAX];
		BitSet[] pr = new BitSet[MAX];
		BitSet[] pu = new BitSet[MAX];
		BitSet[] pd = new BitSet[MAX];
		for (int i = 0; i < MAX; i++) {
			pl[i] = new BitSet(MAX);
			pr[i] = new BitSet(MAX);
			pu[i] = new BitSet(MAX);
			pd[i] = new BitSet(MAX);
		}
		for (int j = minj - 1; j <= maxj + 1; j++) {
			pl[j].or(pl[j - 1]);
			pl[j].or(mapl[j]);
		}
		for (int j = maxj + 1; j >= minj - 1; j--) {
			pr[j].or(pr[j + 1]);
			pr[j].or(mapr[j]);
		}
		for (int i = mini - 1; i <= maxi + 1; i++) {
			pu[i].or(pu[i - 1]);
			pu[i].or(mapu[i]);
		}
		for (int i = maxi + 1; i >= mini - 1; i--) {
			pd[i].or(pd[i + 1]);
			pd[i].or(mapd[i]);
		}

		long ans = 0;
		for (int i = mini - 1; i <= maxi + 1; i++) {
			for (int j = minj - 1; j <= maxj + 1; j++) {
				if ((pl[j].get(i) && pr[j].get(i))
						|| (pu[i].get(j) && pd[i].get(j))) {
					//System.out.println(i + " " + j);
					ans++;
				}
			}
		}
		return ans - s;
	}

	public void run() {
		int T = ni();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			long ans = comp();
			out.println(ans);
		}
		out.close();
	}

}

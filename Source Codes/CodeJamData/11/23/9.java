import java.util.*;
import java.io.*;
import java.math.*;

public class C
{
	public static void main(String[] argv) throws IOException
	{
		new C().run();
	}
	Scanner in;
	PrintWriter out;

	class Poly{
		int n;
		ArrayList<Integer> vert;
		public Poly(){
			n = 0;
			vert = new ArrayList<Integer>();
		}
		void add(int v){
			n++;
			vert.add(v);
		}
		int get(int i){
			return vert.get(i);
		}
		void cut(boolean[][] adj, ArrayList<Poly> polygons){
			for (int i = 0; i < n; i++){
				for (int j = i + 2; j < n; j++){
					if (i == 0 && j == n-1) continue;
					if (adj[get(i)][get(j)]){
						Poly left = new Poly();
						Poly right = new Poly();
						for (int h = 0; h < n; h++){
							if (h <= i || h >= j) left.add(get(h));
							if (h >= i && h <= j) right.add(get(h));
						}
						left.cut(adj, polygons);
						right.cut(adj, polygons);
						return;
					}
				}
			}
			polygons.add(this);
		}
	}

	ArrayList<Poly> polygons;
	int[] color;
	int[] bcolor;
	int ans;

	boolean check(int[] color, int cmax, ArrayList<Poly> polygons){
		boolean[] haveColor = new boolean[cmax + 1];
		for (Poly p : polygons){
			Arrays.fill(haveColor, false);
			for (Integer v: p.vert){
				haveColor[color[v]] = true;
			}
			for (int i = 0; i <= cmax; i++){
				if (!haveColor[i]) return false;
			}
		}
		return true;
	}

	void go(int n, int pos, int cmax){
		if (pos == n){
			if (cmax > ans && check(color, cmax, polygons)){
				ans = cmax;
				bcolor = Arrays.copyOf(color, n);
			}
			return;
		}
		for (int i = 0; i <= cmax; i++){
			color[pos] = i;
			go(n, pos + 1, cmax);
		}
		color[pos] = cmax + 1;
		go(n, pos + 1, cmax + 1);
	}

	int solve(boolean[][] adj){
		int n = adj.length;
		polygons = new ArrayList<Poly>();
		Poly poly = new Poly();
		for (int i = 0; i < n; i++) poly.add(i);
		poly.cut(adj, polygons);
		color = new int[n];
		color[0] = 0;
		ans = 0;
		go(n, 1, 0);
		return ans + 1;
	}

	public void run() throws IOException
	{
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		in = oj ? new Scanner(System.in) : new Scanner(new File("input.txt"));
		out = oj ? new PrintWriter(System.out) : new PrintWriter(new File("output.txt"));

		int testNum = in.nextInt();
		for (int t = 0; t < testNum; t++){
			int n = in.nextInt();
			int m = in.nextInt();
			boolean[][] adj = new boolean[n][n];
			int[] us = new int[m];
			for (int i = 0; i < m; i++){
				us[i] = in.nextInt() - 1;
			}
			for (int i = 0; i < m; i++){
				int v = in.nextInt() - 1;
				adj[us[i]][v] = true;
				adj[v][us[i]] = true;
			}
			out.println("Case #" + (t+1) + ": " + solve(adj));
			for (int i = 0; i < n; i++){
				out.print((bcolor[i] + 1) + " ");
			}
			out.println();
			out.flush();
			System.err.println(t);
		}
	}
}

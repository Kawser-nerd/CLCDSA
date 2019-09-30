import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readNM(in.readLine());
		for (; solver.hasNextLink();)
			solver.readLink(in.readLine());
		solver.readQ(in.readLine());
		for (; solver.hasNextPaint();)
			solver.readPaint(in.readLine());
		solver.solve();
	}
}

class Solver {

	Vertex[] Vertexes;

	class Vertex {
		int Idx;
		int[] Color;
		ArrayList<Integer> Link;

		Vertex(int i) {
			Idx = i;
			Color = new int[11];
			Link = new ArrayList<Integer>();
		}

		void AddLink(int v) {
			Link.add(v);
		}

		void Paint(int d, int c) {
			if (Color[d] != 0)
				return;
			// System.out.println(Idx + " " + d + " " + c);
			Color[d] = c;
			if (d > 0) {
				Vertexes[Idx].Paint(d - 1, c);
				for (int next : Link) {
					Vertexes[next].Paint(d - 1, c);
				}
			}
		}
	}

	int N;
	int M;
	int Q;
	int cntM;
	int cntQ;

	public void init() {
		N = 0;
		M = 0;
		Q = 0;
		cntM = 0;
		cntQ = 0;
	}

	public void readNM(String str) {
		String[] strArr = str.split(" ");
		N = Integer.parseInt(strArr[0]);
		M = Integer.parseInt(strArr[1]);
		Vertexes = new Vertex[N + 1];
		for (int i = 1; i <= N; i++)
			Vertexes[i] = new Vertex(i);
	}

	public boolean hasNextLink() {
		return cntM < M;
	}

	public void readLink(String str) {
		String[] strArr = str.split(" ");
		int a = Integer.parseInt(strArr[0]);
		int b = Integer.parseInt(strArr[1]);
		Vertexes[a].AddLink(b);
		Vertexes[b].AddLink(a);
		cntM++;
	}

	int[] V;
	int[] D;
	int[] C;

	public void readQ(String str) {
		Q = Integer.parseInt(str);
		V = new int[Q];
		D = new int[Q];
		C = new int[Q];
	}

	public boolean hasNextPaint() {
		return cntQ < Q;
	}

	public void readPaint(String str) {
		String[] strArr = str.split(" ");
		V[cntQ] = Integer.parseInt(strArr[0]);
		D[cntQ] = Integer.parseInt(strArr[1]);
		C[cntQ] = Integer.parseInt(strArr[2]);
		cntQ++;
	}

	public void solve() {
		for (int i = Q - 1; i >= 0; i--) {
			// System.out.println(V[i] + " " + D[i] + " " + C[i]);
			Vertexes[V[i]].Paint(D[i], C[i]);
		}
		for (int i = 1; i <= N; i++)
			System.out.println(Vertexes[i].Color[0]);
	}
}
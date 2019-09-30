



import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;


public class D {
	// TODO: input data variables
	boolean graph[][];
	boolean graph2[][];
	int N,M;
	public void read() {
		N = in.nextInt();
		graph = new boolean[N][N]; for(int i=0;i<N;i++) for(int j=0;j<N;j++) graph[i][j] = false;
		for(int i=0;i<N-1;i++) {
			int a = in.nextInt()-1;
			int b = in.nextInt()-1;
			graph[a][b] = graph[b][a]=true;
		}
		M = in.nextInt();
		graph2 = new boolean[M][M]; for(int i=0;i<M;i++) for(int j=0;j<M;j++) graph2[i][j] = false;
		for(int i=0;i<M-1;i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			graph2[a][b] = graph2[b][a] = true;
		}
	}

	// TODO: define answer variable, e.g. long count;
	// TODO: define working variables
	boolean ans;
	boolean used [];
	public void work() {
		int map[] = new int[M];
		used = new boolean[N]; for(int i=0;i<N;i++) used[i] = false;
		ans = fill(map,0);

	}
	private boolean fill(int map[],int pos) {
		if (pos == M) return check(map);
		for(int i=0;i<N;i++) if (!used[i]) {
			map[pos]=i;
			used[i] = true;
			if (fill(map,pos+1)) return true;
			used[i] = false;
		}
		return false;

	}

	private boolean check(int[] map) {
//		for(int i=0;i<M;i++) con.print(map[i]);
//		con.println();
//		if (map[0]==2 && map[1]==0 && map[2]==3 && map[3]==4) {
//			int x;
//			x=3;
//		}
		for(int i=0;i<M;i++) for(int j=0;j<M;j++) {
			if (graph2[i][j]!=graph[map[i]][map[j]])
				return false;
		}
//		for(int i=0;i<M;i++) {
//			con.printf("%d\t%d\n",i,map[i]);
//		}
		return true;
	}
	public void kill() {
		int ___N;
		___N = in.nextInt();
		in.nextLine();
		for(int tc=1;tc<=___N;tc++) {
			read();
			con.println("Case #"+tc+": ");
			work();
			out.print("Case #"+tc+": ");
			// TODO: print answer here
			out.print(ans?"YES":"NO");
			out.println();
		}
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		D self = new D();
		self.init();
		self.kill();
		self.clean();
		self.con.println("done");
	}


	// Below is for i/o only -------------------------------
	Scanner in;
	PrintStream out;
	PrintStream con;
	// PrintWriter out;

	public void init() throws IOException {
		con = System.err;

		BufferedReader console = new BufferedReader(
					new InputStreamReader(System.in));
		System.err.print("Read from (empty for stdin/stdout):");
		String in = console.readLine();
		if (in.length() == 0) {
			this.in =  new Scanner(System.in);
			this.out = System.out;
		} else {
			int pos = in.lastIndexOf(".");
			if (pos<0) {
				pos = in.length();
				in += ".in";
			}
			this.in =  new Scanner(new FileReader(in));
			in = in.substring(0,pos);

			String out = in + ".out";
			int k = 0;
			while (new java.io.File(out).exists()) {
				out = in + ".out"+(++k);
			}
			if (k>0) {
				System.err.println("Warn: Output file exists. Rename to "+out);
			}
			this.out = new PrintStream(out);
		}
	}
	public void clean() {
		in.close();
		out.flush();
		out.close();
	}
	public void terminate(String war) {
		con.println(war);
		throw new java.lang.RuntimeException("Error:"+war);
		// System.exit(1);
	}

	// common procedures
	static public int gcd(int a, int b) {
		while (b>0) {
			int tmp = a % b;
			a = b; b = tmp;
		}
		return a;
	}
}

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A{
	Scanner sc = new Scanner(System.in);
	PrintStream out = System.out;
	
	int N;
	int[][] adj;
	boolean[] visited;
	
	void read() {
		N = sc.nextInt();
		adj = new int[N+1][];
		for (int i = 1; i <= N; i++) {
			int m = sc.nextInt();
			adj[i] = new int[m];
			for (int j=0; j<m; ++j) 
				adj[i][j] = sc.nextInt();
		}
	}
	
	boolean visit(int n) {
		if (visited[n]) return true;
		visited[n] = true;
		for (int i=0; i<adj[n].length; ++i) {
			if (visit(adj[n][i])) return true;
		}
		return false;
	}
	
	void solve() {
		boolean yes = false;
		visited = new boolean[N+1];
		for (int i=1; i<=N; ++i) {
			for (int j=0; j<=N; ++j) visited[j] = false;
			if (visit(i)) {
				yes = true;
				break;
			}
		}
		if (yes) out.println("Yes");
		else out.println("No");
	
	}
	
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		Locale.setDefault(new Locale("en", "US"));
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}

import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class C{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		int T = INT(in.readLine());
		for(int i = 1; i <= T; i++){
			System.out.printf("Case #%d: ",i);
			new C().go();
		}
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		ST();
		int n = INT(st.nextToken());
		int k = INT(st.nextToken());
		int[][] ps = new int[n][k];
		for(int i = 0; i < n; i++){
			ST();
			for(int j = 0; j < k; j++){
				ps[i][j] = INT(st.nextToken());
			}
		}
		g = new boolean[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				boolean bigger = false;
				boolean smaller = false;
				for(int m = 0; m < k; m++){
					if(ps[i][m] >= ps[j][m]) bigger = true;
					if(ps[i][m] <= ps[j][m]) smaller = true;
				}
				if(bigger && smaller) continue;
				if(smaller) g[i][j] = true;
			}
		}
		int ans = n;
		match = new int[n];
		fill(match, -1);
		for(int i = 0; i < n; i++){
			been = new boolean[n];
			if(match(i)) ans--;
		}
		System.out.println(ans);
		for(int i = 0; i < n; i++){
			//System.out.println("Connected "+i+" to "+match[i]);
		}
	}

	boolean[][] g;
	boolean[] been;
	int[] match;

	boolean match(int at){
		if(been[at]) return false;
		been[at] = true;
		for(int i = 0; i < g.length; i++){
			if(g[at][i] && (match[i] == -1 || match(match[i]))){
				match[i] = at;
				return true;
			}
		}
		return false;
	}

}
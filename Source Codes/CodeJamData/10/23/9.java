import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class C implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	final static int modulo = 100003;
	final static int maxN = 500;
	long memo[][];
	long cnk[][];
	
	public long calc(int order, int num) {
		if( order >= num ) {
			return 0;
		}
		if( memo[order][num] > 0 ) {
			return memo[order][num];
		}
		if( order == 1 ) {
			return 1;
		}
		memo[order][num] = 0;
		for( int i = 1; i < order; i++ ) {
			memo[order][num] = (memo[order][num] + cnk[order - i - 1][num - order - 1] * calc(i, order)) % modulo;
		}
		return memo[order][num];
	}
	
	public void preProcess()
	{
		int n = maxN;
		cnk = new long[n+1][n+1];
		for( int i = 0; i <= n; i++ ) {
			cnk[0][i] = 1;
		}
		for( int i = 1; i <= n; i++ ) {
			for( int j = i; j <= n; j++ ) {
				cnk[i][j] = (cnk[i-1][j-1] + cnk[i][j-1]) % modulo;
			}
		}
		memo = new long[n+1][n+1];
		for( int i = 0; i < n + 1; i++ ) {
			Arrays.fill(memo[i], -1);
		}
		for( int i = 2; i <= n; i++ ) {
			for( int j = 1; j < i; j++ ) {
				calc(j,i);
			}
		}
	}
	
	public void solve() throws Exception 
	{
		int n = Integer.parseInt(readword());
		long ans = 0;
		for( int i = 1; i < n; i++ ) {
			ans = (ans + calc(i,n)) % modulo;
		}
		out.write(ans + "\n");
	}
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) c = in.read();
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			c = in.read();
		}
		return bld.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(this.getClass().getName() + ".in"));
			out = new BufferedWriter(new FileWriter(this.getClass().getName() + ".out"));
			int tn = Integer.parseInt(readword());
			preProcess();
			for( int i = 0; i < tn; i++ ) {
				out.write("Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	public static void main(String[] args) {
		new Thread(new C()).start();
	}
}

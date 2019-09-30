import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;

public class A implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	public void solve() throws Exception 
	{
		int n = Integer.parseInt(readword());
		int m = Integer.parseInt(readword());
		String s[][] = new String[n+m][];
		for( int i = 0; i < n + m; i++ ) {
			String tmp = readword();
			String[] ar = tmp.split("/");
			s[i] = ar;
		}
		HashSet<String> paths = new HashSet<String>();
		int answer = 0;
		for( int i = 0; i < n + m; i++ ) {
			String cur = "";
			for( int j = 0; j < s[i].length; j++ ) {
				if( s[i][j].length() == 0 ) continue;
				cur = cur + "/" + s[i][j];
				if( !paths.contains(cur) ) {
					paths.add(cur);
					if( i >= n ) {
						answer++;
					}
				}
			}
		}
		out.write(answer + "\n");
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
		new Thread(new A()).start();
	}
}

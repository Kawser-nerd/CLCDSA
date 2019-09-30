import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class C implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	static {
		inputFile = C.class.getName() + ".in";
		outputFile = C.class.getName() + ".out";
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}
	
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	
	public String readword() throws Exception {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) {
			c = in.read();
		}
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			c = in.read();
		}
		return bld.toString();
	}

	final static String target = "welcome to code jam";
	public void solve() throws Exception {
		String s = in.readLine();
		int ans[][] = new int[s.length()+1][target.length()+1];
		ans[0][0] = 1;
		for( int i = 0; i < s.length(); i++) {
			for( int j = 0; j < target.length(); j++ ){
				if( target.charAt(j) == s.charAt(i)) {
					ans[i+1][j+1] = (ans[i][j] + ans[i+1][j+1])%10000;
				}
				ans[i+1][j] = (ans[i][j] + ans[i+1][j]) % 10000;
			}
		}
		int result = 0;
		for( int i = 0; i <= s.length(); i++) {
			result = (result + ans[i][target.length()]) % 10000;
		}
		result += 10000;
		out.write( Integer.toString(result).substring(1) + "\n");
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			int tests = Integer.parseInt(in.readLine());
			for( int i = 0; i < tests; i++) {
				out.write( "Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread( new C()).start();
	}

}

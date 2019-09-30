import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class A implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	static {
		inputFile = A.class.getName() + ".in";
		outputFile = A.class.getName() + ".out";
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
	
	public void solve() throws Exception {
		int len = iread();
		int n = iread();
		int tests = iread();
		String words[] = new String[n];
		for( int i = 0; i < n; i++) {
			words[i] = readword();
		}
		for( int i = 0; i < tests; i++) {
			boolean cand[] = new boolean[n];
			Arrays.fill(cand,true);
			String pat = readword();
			int curPos = 0;
			for( int j = 0; j < len; j++) {
				String match = "";
				if( pat.charAt(curPos) == '(') {
					int temp = curPos + 1;
					while( pat.charAt(temp) != ')') {
						temp++;
					}
					match = pat.substring(curPos+1, temp);
					curPos = temp + 1;
				} else {
					match = "" + pat.charAt(curPos);
					curPos++;
				}
				for( int t = 0; t < n; t++) {
					boolean flag = false;
					for( int k = 0; k < match.length(); k++) {
						if( words[t].charAt(j) == match.charAt(k)) flag = true;
					}
					cand[t] = cand[t] & flag;
				}
			}
			int result = 0;
			for( int j = 0; j < words.length; j++) {
				if( cand[j] ) result++;
			}
			out.write("Case #" + (i+1) + ": " + result + "\n");
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			solve();
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread( new A()).start();
	}

}

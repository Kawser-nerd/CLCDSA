import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class B implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	static {
		inputFile = B.class.getName() + ".in";
		outputFile = B.class.getName() + ".out";
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
	
	public boolean nextPerm( int a[] ) {
		for( int i = a.length - 1; i >= 1; i-- ) {
			if( a[i] > a[i-1] ) {
				int index = -1;
				for( int j = i; j < a.length; j++) {
					if( a[j] > a[i-1] ) {
						if( index == -1 || a[index] > a[j] ) {
							index = j;
						}
					}
				}
				int buf = a[i-1];
				a[i-1] = a[index];
				a[index] = buf;
				Arrays.sort(a,i,a.length);
				return true;
			}
		}
		return false;
	}
	
	public void print( int a[] ) throws Exception {
		for( int i = 0; i < a.length; i++) {
			out.write(Integer.toString(a[i]));
		}
		out.write("\n");
	}
	
	public void solve() throws Exception {
		String s = readword();
		int a[] = new int[s.length()];
		for( int j = 0; j < s.length(); j++) {
			a[j] = s.charAt(j) - '0';
		}
		if( nextPerm(a) ) {
			print(a);
		} else {
			Arrays.sort(a);
			int b[] = new int[a.length+1];
			for( int i = 0; i < a.length; i++) {
				b[i+1] = a[i];
			}
			Arrays.sort(b);
			for( int i = 0; i < b.length; i++) {
				if( b[i] > 0 ) {
					int buf = b[i];
					b[i] = b[0];
					b[0] = buf;
					break;
				}
			}
			print(b);
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			int n = Integer.parseInt(readword());
			for( int i = 0; i < n; i++) {
				out.write("Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread( new B()).start();
	}

}

import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	StreamTokenizer ST;
	PrintWriter out;
	BufferedReader br;
	// Scanner in;
	String FileName = "test";
	int inf = 1000000000;

	int nextInt() throws IOException {
		ST.nextToken();
		return (int) ST.nval;
	}

	String next() throws IOException {
		ST.nextToken();
		return ST.sval;
	}

	double nextD() throws IOException {
		ST.nextToken();
		return ST.nval;
	}

	public static void main(String[] args) throws IOException {
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter(new File(
					"output.txt"))));
			br = new BufferedReader(new FileReader("input.txt"));
			// in = new Scanner(br);
			ST = new StreamTokenizer(br);
			solve();
			out.close();
		} catch (IOException e) {
			throw new IllegalStateException(e);
		}
	}

	public void solve() throws IOException {
		 int test = nextInt();
	     for (int tt=1; tt<=test; tt++) {
	          out.print("Case #"+tt+": ");
	          int p = nextInt();
	          int k = nextInt();
	          int n = nextInt();
	          int[] a = new int[n];
	          for (int i=0; i<n; i++) a[i] = nextInt();
	          if (n>k*p) {
	               out.println("Impossible");
	               continue;
	          }
	          Arrays.sort(a);
	          int[] r = new int[k];
	          Arrays.fill(r, p);          
	     
	          long res = 0;
	          int h = 1;
	          int kk = 1;
	          for (int i=n-1; i>=0; --i) {
	               res += a[i]*h;
	               kk++;
	               if (kk>k) {
	                    kk = 1;
	                    h++;
	               }
	          }     
	          out.println(res);
	     }
	}
}
import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	PrintWriter out;  
	StringTokenizer st = new StringTokenizer("");
	
	public static void main(String [] args) throws Exception {
		new Thread(new Main()).start();
	}


	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter("out.txt");

			int T = nextInt();
			for (int cases = 0; cases < T; cases++) {
			        int n = nextInt(), k = nextInt(), b = nextInt(), t = nextInt();
			        int [] x = new int [n];
			        int [] v = new int [n];
			        for (int i = 0; i < n; i++)
			        	x[i] = nextInt();
			        for (int i = 0; i < n; i++)
			        	v[i] = nextInt();


			        int [] min = new int [n];
			        for (int i = 0; i < n; i++) {
			        	if (b - x[i] > t * v[i]) {
			        		
			        		min[i] = 10000;
			        		continue;
			        	}
			        	for (int j = 0; j < n; j++) {
			        		if (x[j] <= x[i]) continue;
			        		if (b - x[j] > t * v[j])
			        			min[i]++;
			        	}
			        }

			        Arrays.sort(min);
			        int res = 0;
			        for (int i = 0; i < k; i++) {
			        	res += min[i];	
			        }



				out.println("Case #" + (cases + 1) + ": " + (res < 10000 ? res : "IMPOSSIBLE"));
			}


			out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	 boolean seekForToken() {
 		try {
			while (!st.hasMoreTokens()) {
				String s = in.readLine();
				if (s == null) {
				 	return false;
				}
			 	st = new StringTokenizer(s);
			}
			return true;
		}
		catch (IOException e) {
		 	e.printStackTrace();
		 	return false;
		}
 	}

 	 int nextInt() {
		return Integer.parseInt(nextToken());
 	}

 	 long nextLong() {
		return Long.parseLong(nextToken());
 	}

 	 double nextDouble() {
		return Double.parseDouble(nextToken());
 	}

 	 BigInteger nextBigInteger() {
 	 	return new BigInteger(nextToken());
 	}

 	 String nextToken() {
 	 	seekForToken();
 	 	return st.nextToken();
 	}

}

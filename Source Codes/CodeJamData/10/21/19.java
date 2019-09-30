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

	class Dir {
     		HashMap <String, Dir> subDir = new HashMap <String, Dir> ();

     		Dir addSubDir(String name) {
     			Dir toAdd = new Dir();
     			subDir.put(name, toAdd);
     			return toAdd;	
     		}

     		boolean hasSubDir(String name) {
     			return subDir.containsKey(name);
     		}

     		Dir getSubDir(String name) {
     			return subDir.get(name);
     		}
	}


	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter("out.txt");

			int T = nextInt();
			for (int cases = 0; cases < T; cases++) {
			        int n = nextInt(), m = nextInt();
			        int res = 0;
			        Dir root = new Dir();
			        for (int i = 0; i < n; i++) {
			        	Dir curDir = root;
			        	String dirname = in.readLine();
			        	String [] w = dirname.split("/");
			        	for (int j = 1; j < w.length; j++) {
			        		if (curDir.hasSubDir(w[j])) curDir = curDir.getSubDir(w[j]);
			        		else curDir = curDir.addSubDir(w[j]);		
			        	}
			        }

			        for (int i = 0; i < m; i++) {
			        	Dir curDir = root;
			    		String dirname = in.readLine();
			        	String [] w = dirname.split("/");
			        	for (int j = 1; j < w.length; j++) {
			        		if (curDir.hasSubDir(w[j])) curDir = curDir.getSubDir(w[j]);
			        		else {
			        			curDir = curDir.addSubDir(w[j]);		
			        			res++;
			        		}
			        	}
			        }

				out.println("Case #" + (cases + 1) + ": " + res);
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

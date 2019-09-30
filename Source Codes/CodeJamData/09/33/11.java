import java.io.*;
import java.util.*;

public class Main extends Thread {

	Scanner in;
	PrintWriter out;
		
	final int MAX = 100000;
	
	
	int p;
	int nq;
	int[] q;
	
	HashMap<Integer, Integer>[] h;
	
	int rec(int i, int j) {
		if (i > j) return 0;
		
		if (h[i].containsKey(j)) return h[i].get(j);
		
		int l = -1;
		for (int k = 0; k < nq; k++)
			if (q[k] >= i && q[k] <= j) {
				l = k;
				break;
			}
		int ret = 0;
		if (l != -1) {
			ret = MAX;
			for (int k = l; k < nq && q[k] <= j; k++)
				ret = Math.min(ret, j-i + rec(i, q[k]-1) + rec(q[k]+1, j));
		}
		
		h[i].put(j, ret);
		return ret;
	}
	
	public void run() {
		try {				
			in = new Scanner(new File("small.in"));		
			out = new PrintWriter("small.out");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
			
		int test = in.nextInt();

		for (int nt = 1; nt <= test; nt++) {
			p = in.nextInt();
			nq = in.nextInt();
			
			q =  new int[nq];
			for (int i = 0; i < nq; i++)
				q[i] = in.nextInt();
			Arrays.sort(q);
						
			h = new HashMap[p+1];
			for (int i = 1; i <= p; i++)
				h[i] = new HashMap<Integer, Integer>();
			int ret = rec(1, p);
			out.println("Case #" + nt + ": " + ret);													
		}

		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
}

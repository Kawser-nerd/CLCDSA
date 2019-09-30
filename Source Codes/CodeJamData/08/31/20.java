import java.io.*;
import java.util.*;

public class TaskA implements Runnable{

	/**
	 * @param args
	 */
	
	static BufferedReader br = null;
	static StringTokenizer stk = null;
	static PrintWriter pw = null;
	
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter("a.out");
		(new Thread(new TaskA())).run();
	}

	public void nline() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public int ni() {
		while (stk==null||!stk.hasMoreTokens()) nline();
		return Integer.valueOf(stk.nextToken());
	}
	
	public double nd() {
		while (stk==null||!stk.hasMoreTokens()) nline();
		return Double.valueOf(stk.nextToken());
	}

	public long nl() {
		while (stk==null||!stk.hasMoreTokens()) nline();
		return Long.valueOf(stk.nextToken());
	}
	
	public void solve(int tn){
		int p = ni();
		int k = ni();
		int l = ni();
		long s[] = new long[l];
		for (int i=0;i<l;i++)
			s[i] = ni();
		Arrays.sort(s);
		long ans = 0;
		int j = 1;
		int pp = 0;
		for (int i = l-1; i > -1; i--){
			ans += s[i]*j;
			pp++;
			if (pp == k) {
				pp = 0;
				j++;
			}
		}
		if (p*k<l)
			pw.println("Case #"+tn+": impossible");
		else
			pw.println("Case #"+tn+": " + ans);
	}
	
	public void run() {
		int n = ni();
		for (int i=0;i<n;i++)
			solve(i+1);
		pw.close();
	}

}
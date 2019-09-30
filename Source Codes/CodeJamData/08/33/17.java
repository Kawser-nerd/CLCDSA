import java.io.*;
import java.util.*;

public class TaskC implements Runnable{

	/**
	 * @param args
	 */
	
	static BufferedReader br = null;
	static StringTokenizer stk = null;
	static PrintWriter pw = null;
	
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter("c.out");
		(new Thread(new TaskC())).run();
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
	
	long magic = 1000000007L;
	
	public void solve(int tn){
		int n = ni(), m = ni();
		long x = ni(), y = ni(), z = ni();
		long mm[] = new long[m];
		for (int i=0;i<m;i++)
			mm[i] = ni();
		long a[] = new long[n];
		for (int i=0;i<n;i++){
			a[i] = mm[i%m];
			mm[i%m] = (x*mm[i%m]+y*(i+1))%z;
		}
		long aa[] = new long[n];
		for (int i=0;i<n;i++){
			long k = 1;
			for (int j=0;j<i;j++)
				if (a[j]<a[i]) k = (k + aa[j])%magic;
			aa[i] = k;
		}
		long ans = 0;
		for (int i=0;i<n;i++)
			ans = (ans + aa[i])%magic;
		pw.println("Case #"+tn+": "+ans);
	}
	
	public void run() {
		int n = ni();
		for (int i=0;i<n;i++)
			solve(i+1);
		pw.close();
	}

}
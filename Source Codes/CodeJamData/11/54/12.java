import java.io.*;
import java.util.*;

public class BaiD {
	
	static String res;
	static char[] b;
	
	static void duyet(char[] a, int pos, long cur) {
		if(res != null) return;
		if(pos == a.length) {
			long z = (long)(Math.sqrt(cur) + 0.1);
			if(z * z == cur) res = new String(b);
			return;
		}
		if(a[pos] == '0') {
			b[pos] = '0';
			duyet( a, pos + 1, cur * 2);
		}
		else if(a[pos] == '1') {
			b[pos] = '1';
			duyet( a, pos + 1, cur * 2 + 1);
		}
		else {
			b[pos] = '0';
			duyet( a, pos + 1, cur * 2);
			b[pos] = '1';
			duyet( a, pos + 1, cur * 2 + 1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		PrintWriter pw = new PrintWriter(new FileWriter("Dsmall.out"));
		
		int ntest = sc.nextInt();
		for(int test=1;test<=ntest;++test) {
			
			char[] a = sc.next().toCharArray();
			b = new char[a.length];
			res = null;
			duyet(a, 0, 0);
			
			
			
			pw.print("Case #" + test + ": ");
			pw.print(res);
			pw.println();
			
		}
		
		sc.close();
		pw.close();
	}
}

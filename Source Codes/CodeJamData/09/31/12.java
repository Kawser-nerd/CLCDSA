import java.io.*;
import java.util.*;

public class Main {

	Scanner in;
	PrintWriter out;
	
	
	
	
	void run() throws IOException {
		in = new Scanner(new File("small.in"));
		out = new PrintWriter("small.out");
		
		int t = in.nextInt();
		in.nextLine();
		for (int nt = 1; nt <= t; nt++) {
			String s = in.nextLine();
			
			int len = s.length();
			int[] a = new int[len];
			int[] dig = new int[10+26];
			Arrays.fill(dig, -1);
			boolean[] was = new boolean[10+26];
			int base = 1;
			for (int i = 0; i < len; i++) {
				char c = s.charAt(i);
				int d = 0;
				if (Character.isDigit(c)) {
					d = c-'0';
				}
				else {
					d = c-'a' + 10;
				}
				
				if (dig[d] != -1) {
					a[i] = dig[d];
				}
				else {				
					int curDig = -1;
					for (int j = (i==0)?1:0; ; j++)
						if (!was[j]) {
							was[j] = true;
							curDig = j;
							break;
						}
					dig[d] = curDig;
					a[i] = curDig;
					base = Math.max(base, curDig+1);
				}
			
				
			}
			long ret = 0;
			for (int i = 0; i < len; i++)
				ret = ret*base + a[i];
			
			out.println("Case #" + nt + ": "+ ret);
		}
		
				
		
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
}

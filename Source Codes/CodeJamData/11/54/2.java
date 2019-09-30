import java.util.*;
import java.math.*;
import java.io.*;

public class Solution {
	String s;
	char[] c;
	String res;
	
	void go(int pos, long have) {
		if (pos == s.length()) {
			long x = (long)Math.round(Math.sqrt(have));
			if (x*x==have) {
				res = new String(c);
			}
			return;
		}
		if (s.charAt(pos) == '0') {
			c[pos]='0';
			go(pos+1, 2*have);
		} else if (s.charAt(pos) == '1') {
			c[pos]='1';
			go(pos+1, 2*have+1);
		} else {
			c[pos]='0';
			go(pos+1, 2*have);
			c[pos]='1';
			go(pos+1, 2*have+1);
		}
	}
	
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("Processing case " + caseNum);
			pw.print("Case #" + caseNum + ": ");
			
			s = sc.next();
			c = new char[s.length()];
			go(0, 0);
			
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}

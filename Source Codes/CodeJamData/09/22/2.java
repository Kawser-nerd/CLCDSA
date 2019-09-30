import java.util.*;
import java.io.*;

public class ProblemB {
	int[] d;
	
	String getSolution(String prefix, int add) {
		int[] dd = d.clone();
		for (int i=0; i < prefix.length(); i++)
			if (prefix.charAt(i) != '0') {
				dd[prefix.charAt(i) - '0']--;
			}
		int need = 0;
		for (int i=1; i <= 9; i++) {
			if (dd[i] < 0) return "";
			need += dd[i];
		}
		if (need > add) return "";
		dd[0] = add - need;
		String res = prefix;
		for (int i=0; i < 10; i++)
			for (int j=0; j < dd[i]; j++)
				res += ""+i;
		return res;
	}
	
	String solve(String s) {
		for (int len=s.length()-1; len >= 0; len--)
			for (char next=(char)((int)s.charAt(len) + 1); next <= '9'; next++) {
				String ans = getSolution(s.substring(0, len)+ "" + (char)next, s.length() - len - 1);
				if (!ans.equals("")) return ans;
			}
		for (int len=s.length(); ; len++)
			for (char st = '1'; st <= '9'; st++) {
				String ans = getSolution(""+(char)st, len);
				if (!ans.equals("")) return ans;
			}
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			String curNum = sc.next();
			d = new int[10];
			for (int i=0; i < curNum.length(); i++)
				if (curNum.charAt(i) != '0')
					d[curNum.charAt(i)-'0']++;
			pw.println("Case #" + caseNum + ": " + solve(curNum));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemB()).doMain();
	}
}
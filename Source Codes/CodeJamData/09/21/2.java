import java.util.*;
import java.io.*;

public class ProblemA {
	int pos;
	
	String getItem(String s, String chars, boolean single) {
		while (Character.isWhitespace(s.charAt(pos))) pos++;
		String res = "";
		while (chars.indexOf(s.charAt(pos)) != -1) {
			res += (char)s.charAt(pos);
			pos++;
			if (single) break;
		}
		return res;
	}
	
	class Tree {
		String feat;
		double p;
		Tree left, right;
		
		public Tree(String s) {
			//System.out.println(s.substring(pos));
			getItem(s, "(", true);
			
			p = Double.parseDouble(getItem(s, "1234567890.", false));
			
			while (Character.isWhitespace(s.charAt(pos))) pos++;
			
			if (s.charAt(pos) != ')') {
			
				feat = getItem(s, "qwertyuiopasdfghjklzxcvbnm", false);
			
				left = new Tree(s);
				right = new Tree(s);
			}
			
			getItem(s, ")", true);
		}
	}
	
	public void doMain() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = Integer.parseInt(br.readLine());
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			// input
			int L = Integer.parseInt(br.readLine());
			String s = "";
			for (int i=0; i<L; i++) s += br.readLine();
			
			// solution
			pw.println("Case #" + caseNum + ":");
			
			pos = 0;
			Tree t = new Tree(s);
			
			int A = Integer.parseInt(br.readLine());
			for (int i=0; i < A; i++) {
				Set<String> have = new HashSet<String>();
				StringTokenizer st = new StringTokenizer(br.readLine());
				st.nextToken();
				int n = Integer.parseInt(st.nextToken());
				for (int j=0; j<n; j++) have.add(st.nextToken());
				
				double res = 1.0;
				Tree cur = t;
				while (true) {
					res *= cur.p;
					if (cur.left == null) break;
					cur = (have.contains(cur.feat) ? cur.left : cur.right);
				}
				
				pw.println(res);				
			}
			
			// output
		}
		
		pw.flush();
		pw.close();
		br.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}
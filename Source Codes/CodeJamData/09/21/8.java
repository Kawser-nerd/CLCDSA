import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Task {
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		new Task().run();
		out.close();
	}
	
	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String taskName = "";
	
	String nline() {
		try {
			return br.readLine();
		} catch (Exception exc) {
			return  null;
		}
	}
	
	String ns() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(nline());
			}
			return st.nextToken();
		} catch (Exception exc) {
			return null;
		}
	}
	
	int ni() {
		return Integer.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}
	
	void pf(String format, Object ... obj) {
		out.printf(format, obj);
	}
	
	void pln() {
		out.println();
	}
	
	void pt(Object obj) {
		out.print(obj);
	}
	
	boolean check(char ch) {
		return ch != ' ' && ch != '(' && ch != ')';
	}
	
	class Tree {
		int lineNum;
		Tree left, right;
		double weight;
		String name;
		
		Tree(String s, int from, int to) {
			while (s.charAt(from) != '(')
				from++;
			while (s.charAt(to) != ')')
				to--;
			from++;
			while (s.charAt(from) == ' ')
				from++;
			
			int pos = from + 1; 
			while (s.charAt(pos) != ' ' && s.charAt(pos) != ')' && s.charAt(pos) != '(')
				pos++;
			
			String sNum = s.substring(from, pos);
			weight =Double.parseDouble(sNum.trim());
			
			while (s.charAt(pos) == ' ')
				pos++;
			
			if (pos == to) 
				return;
			
			int pos1 = pos;
			while (check(s.charAt(pos1)))
				pos1++;
			
			name = s.substring(pos, pos1);
			
			int med = pos1;
			int cnt = 1;
			while (s.charAt(med) != '(')
				med++;
			
			while (cnt != 0) {
				med++;
				if (s.charAt(med) == '(')
					cnt++;
				if (s.charAt(med) == ')')
					cnt--;
			}
			
			left = new Tree(s, pos1, med);
			right = new Tree(s, med + 1, to - 1);
		}
		
		double getProb(TreeSet<String> set, double p) {
			p *= weight;
			if (name == null)
				return p;
			
			if (set.contains(name))
				return left.getProb(set, p);
			else
				return right.getProb(set, p);
		}
		
	}
	
	int niLine() {
		return Integer.valueOf(nline().trim());
	}
	
	void run() {
		//Place your code here
		int T = niLine();
		for (int t = 1; t <= T; t++){
			out.printf("Case #%d:", t);
			out.println();
			
			int L = niLine();
			String[] arr = new String[L];
			for (int i = 0; i < L; i++)
				arr[i] = nline().trim();
			
			
			StringBuilder sb = new StringBuilder();
			for (String s : arr)
				sb.append(s + " ");
			
			String desc = sb.toString().replace(" +", " ").trim();
			
			Tree tree = new Tree(desc, 0, desc.length() - 1);
			
			int n = ni();
			for (int i = 0; i < n; i++) {
				TreeSet<String> set = new TreeSet<String>();
				ns();
				int k = ni();
				for (int j = 0; j < k; j++)
					set.add(ns());
				double res = tree.getProb(set, 1);
				out.printf("%.7f", res);
				out.println();
			}
			
			
			
			
		}
	}
}
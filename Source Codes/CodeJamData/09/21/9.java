import java.io.*;
import java.util.*;

public class Gcjr1p1 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("result.txt"));
			
			String s = br.readLine();
			
			int N = Integer.parseInt(s);
			
			for(int i = 1; i <= N; i++) {
				int L = Integer.parseInt(br.readLine());
				
				String tot = "";
				for(int j = 0; j < L; j++) {
					s = br.readLine();
					tot += " " + s;
				}
				
				tot = tot.trim();
				DTree root = addTree(tot);
				
				pw.println("Case #" + i + ":");
				
				int A = Integer.parseInt(br.readLine());
				for(int j = 0; j < A; j++) {
					s = br.readLine().trim();
					
					int v = s.indexOf(" ");
					s = s.substring(v + 1).trim();
					v = s.indexOf(" ");
					s = s.substring(v + 1).trim();
					TreeSet<String> set = new TreeSet<String>();
					String[] ss = s.split(" +");
					for(int k = 0; k < ss.length; k++) {
						set.add(ss[k]);
					}
					
					double res = getVal(root, set);
					pw.println(res);
				}
			}
			
			pw.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static double getVal(DTree tree, Set<String> set) {
		double res = tree.weight;
		if(tree.feature != null) {
			if(set.contains(tree.feature)) {
				res *= getVal(tree.left, set);
			} else {
				res *= getVal(tree.right, set);
			}
		}
		
		return res;
	}
	
	static DTree addTree(String tot) {
		DTree ctree = null;
		tot = tot.substring(1, tot.length() - 1);
		tot = tot.trim();
		int val = tot.indexOf(" ");
		if(val == -1) {
			val = tot.length();
		}
		double w = Double.parseDouble(tot.substring(0, val));
		if(ctree == null) {
			ctree = new DTree();
		}
		
		ctree.weight = w;
		if(val == tot.length()) {
			return ctree;
		}
		tot = tot.substring(val + 1).trim();
		if(tot.length() > 0) {
			val = tot.indexOf(" ");
			String feat = tot.substring(0, val);
			ctree.feature = feat;
			
			tot = tot.substring(val + 1).trim();
			int find = 1, nrOpen = 1;
			while(find < tot.length()) {
				char chr = tot.charAt(find);
				if(chr == '(') {
					nrOpen++;
				} else if(chr == ')') {
					nrOpen--;
				}
				find++;
				if(nrOpen == 0) {
					break;
				}
			}
			
			ctree.left = addTree(tot.substring(0, find));
			ctree.right = addTree(tot.substring(find + 1).trim());
		}
		
		return ctree;
	}
}

class DTree {
	public double weight;
	public String feature;
	public DTree left;
	public DTree right;
}

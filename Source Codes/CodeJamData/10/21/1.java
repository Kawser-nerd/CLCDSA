import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	class Tree {
		Map<String, Tree> mp = new HashMap<String, Tree>();
		
		public Tree() {			
		}
	}
	
	Tree root;
	
	int res;
	
	void process(String s, boolean add) {
		s = s.substring(1);
		String[] items = s.split("/");
		Tree cur = root;
		for (int i=0; i<items.length; i++) {
			if (!cur.mp.containsKey(items[i])) {
				cur.mp.put(items[i], new Tree());
				if (add) res++;
			}
			cur = cur.mp.get(items[i]);
		}
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			int have = sc.nextInt(), next = sc.nextInt();
			
			root = new Tree();
			res = 0;
			
			for (int i=0; i<have; i++) {
				process(sc.next(), false);
			}
			
			for (int i=0; i<next; i++)
				process(sc.next(), true);
			
			pw.println("Case #" + caseNum + ": " + res);
			
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
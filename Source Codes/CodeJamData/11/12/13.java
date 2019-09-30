import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;
import java.util.Map.Entry;


public class Round1AB {
	
	public static String problemName = "B";
	public static String inputName = "large";
	
	public static class R {
		public R(int c, int i) { cost = c; ind = i; }
		int cost;
		int ind;
	}
	
	public static R rec(int[][] sigs, ArrayList<Integer> s, int index, String str) {
		if (index == 26) {
			if (s.size() != 1) {
				System.out.println("Crap!");
				System.out.println(s);
			}
			return new R(0, s.iterator().next());
		}
		
		Map<Integer, ArrayList<Integer> > bitmap = new HashMap<Integer, ArrayList<Integer> >();
		
		for (int i : s) {
			int newsig = sigs[i][str.charAt(index) - 'a'];
			
			if (!bitmap.containsKey(newsig))
				bitmap.put(newsig, new ArrayList<Integer>());
			
			bitmap.get(newsig).add(i);
		}
		
		R res = new R(-1000000, 1000000);
		
		for (Entry<Integer, ArrayList<Integer>> e : bitmap.entrySet()) {
			R sub_res = rec(sigs, e.getValue(), index + 1, str);
			if (e.getKey() == 0 && bitmap.size() > 1) {
				sub_res.cost++;
			}
			
			if (sub_res.cost > res.cost || (sub_res.cost == res.cost && sub_res.ind < res.ind))
				res = sub_res;
		}
		
		return res;
	}
	
	public static String handleCase() {
		int n = in.nextInt();
		int m = in.nextInt();
		
		String[] words = new String[n];
		String[] strategies = new String[m];
		for (int i = 0; i < n; i++) {
			words[i] = in.next();
		}
		
		for (int i = 0; i < m; i++) {
			strategies[i] = in.next();
		}
		
		int[][] signatures = new int[n][27];
		
		for(int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < words[i].length(); k++) {
					signatures[i][words[i].charAt(k)-'a'] |= 1<<k;
				}
			}

			int lastletter = 0;
			for (int j = 0; j < words[i].length(); j++)
				lastletter = Math.max(lastletter, words[i].charAt(j));
			
			signatures[i][26] = lastletter;
		}
		
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < m; i++) {
			R ans = new R(-1000000, 1000000);
			
			HashMap<Integer, ArrayList<Integer>> bysize = new HashMap<Integer, ArrayList<Integer>>();
			for (int j = 0; j < n; j++) {
				if (!bysize.containsKey(words[j].length()))
					bysize.put(words[j].length(), new ArrayList<Integer>());
				bysize.get(words[j].length()).add(j);
			}
			
			for (ArrayList<Integer> sizeclass : bysize.values()) {
				R sub_ans = rec(signatures, sizeclass, 0, strategies[i]);
				
				if (sub_ans.cost > ans.cost ||
						(sub_ans.cost == ans.cost && sub_ans.ind < ans.ind))
					ans = sub_ans;
			}
			
			if (i != 0)
				res.append(" ");
			res.append(words[ans.ind]);
		}
		
		return res.toString();
	}
	
	public static int[] readIntArr() {
		int n = in.nextInt();
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = in.nextInt();
		return res;
	}
	
	public static interface Parser<T> {
		public T next();
	}
	
	public static <T> ArrayList<T> readList (Parser<T> p) {
		int n = in.nextInt();
		ArrayList<T> res = new ArrayList<T>();
		for (int i = 0; i < n; i++)
			res.add(p.next());
		return res;
	}
	
	public static Parser<Integer> intParser = new Parser<Integer>(){
		public Integer next() { return in.nextInt(); }};
	
	public static void main(String[] args) throws FileNotFoundException {
		String inFilename = problemName + "-" + inputName + ".in";
		String outFilename = problemName + "-" + inputName + ".out";
		System.out.println("Reading from " + inFilename);
		System.out.println("Writing to " + outFilename);
		in = new Scanner(new File(inFilename));
		out = new PrintStream(new File(outFilename));
		
		int ncases = in.nextInt();
		
		for (int i = 0; i < ncases; i++) {
			System.out.println("Running case " + (i+1) + "...");
			out.println("Case #" + (i+1) + ": " +
					handleCase()
					)
					;
		}
		System.out.println("Done!");
	}
	
	static Scanner in;
	static PrintStream out;	
}

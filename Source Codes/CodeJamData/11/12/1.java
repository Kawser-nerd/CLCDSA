import java.util.*;
public class B {
	static HashMap<String,Integer> H;
	static String list;
	static int [][] signatures;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			signatures = new int [N][26];
			Bag [] dic = new Bag [11];
			H = new HashMap<String,Integer>(N);
			for (int i = 0; i<N; ++i) {
				String s = sc.next();
				int L = s.length();
				if (dic[L] == null) dic[L] = new Bag();
				dic[L].add(s);
				H.put(s, i);
				for (int j = 0; j<s.length(); ++j) signatures[i][s.charAt(j)-'a'] |= (1<<j);
			}
			StringBuilder ans = new StringBuilder(M*10);
			for (int i = 0; i<M; ++i) {
				list = sc.next();
				Ish best = new Ish("",-1);
				H.put(best.best, Integer.MAX_VALUE);
				for (int L = 1; L<=10; ++L) {
					if (dic[L] == null) continue;
					Ish tmp = recurse(0, dic[L]);
					if (tmp.compareTo(best) < 0) best = tmp;
				}
				ans = (i == 0) ? ans.append(best.best) : ans.append(' ').append(best.best);
			}
			
			System.out.printf("Case #%d: %s\n",ii, ans.toString());
		}
	}
	
	static Ish recurse (int pos, Bag b) {
		if (b.size() == 0) return new Ish("",-1);
		if (b.size() == 1) return new Ish(b.get(0),0);
		for ( ; pos<list.length(); ++pos) {
			if (!b.contains(list.charAt(pos))) continue;
			break;
		}
		if (pos == list.length()) return new Ish(b.get(0),0);
		HashMap<Integer, Bag> H2 = new HashMap<Integer,Bag>();
		char c = list.charAt(pos);
		Ish best = new Ish("",-1);
		
		for (String s : b) {
			int signature = signatures[H.get(s)][c-'a'];
			if (!H2.containsKey(signature)) H2.put(signature, new Bag());
			H2.get(signature).add(s);
		}
		for (int si : H2.keySet()) {
			Bag bi = H2.get(si);
			//if (bi.size() == 0) continue;
			Ish tmp = recurse(pos+1, bi);
			if (si == 0) tmp.best2++;
			if (tmp.compareTo(best) < 0) best = tmp;
		}
		return best;
	}
	
	static class Ish implements Comparable<Ish> {
		String best;
		int best2;
		public Ish (String s, int i) { best2=i; best=s;}
		public int compareTo (Ish i) {
			return (i.best2 == best2) ? H.get(best) - H.get(i.best) : i.best2 - best2;
		}
	}
	
	
	static class Bag extends ArrayList<String> {
		public boolean contains (char let) {
			for (String s : this) if (signatures[H.get(s)][let-'a'] > 0) return true;
			return false;
		}
	
	}
	
}
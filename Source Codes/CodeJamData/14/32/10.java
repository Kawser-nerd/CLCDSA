import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	
	private boolean isSingleLetter(String s) {
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) != s.charAt(0)) {
				return false;
			}
		}
		return true;
	}
	
	private long fac(long n) {
		long res = 1;
		for (int i = 1; i <= n; ++i) {
			res = (res * i)%MOD;
		}
		return res;
	}
	
	private String noBorder(String s) {
		int p1 = 0;
		int p2 = s.length() - 1;
		while (p1 < s.length() && s.charAt(0) == s.charAt(p1)) {
			++p1;
		}
		while (p2 >= 0 && s.charAt(s.length()-1) == s.charAt(p2)) {
			--p2;
		}
		
		if (p1 <= p2) {
			return s.substring(p1, p2+1);
		}
		return "";
	}
	
	private final long MOD = 1000000007;
	public void run() {
		
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			int n = nextInt();
			long ans = 1;
			
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			for (int i = 0; i < n; ++i) {
				String str = nextWord();
				if (!map.containsKey(str)) {
					map.put(str, 0);
				}
				int tmp = map.get(str);
				map.put(str, tmp+1);
			}
			
			boolean fail = false;
			
			//all single - letter
			TreeMap<Character, Integer> onlyBorder = new TreeMap<Character, Integer>();
			TreeSet<String> si = new TreeSet<String>();
			for (String s : map.keySet()) {
				if (isSingleLetter(s)) {
					si.add(s);
					if (!onlyBorder.containsKey(s.charAt(0))) {
						onlyBorder.put(s.charAt(0), 0);
					}
					int cnt = onlyBorder.get(s.charAt(0));
					onlyBorder.put(s.charAt(0), cnt + map.get(s));
				}
				else if (map.get(s) > 1) {
					fail = true;
				}
			}
			
			for (char c : onlyBorder.keySet()) {
				ans = (ans * fac(onlyBorder.get(c)))%MOD;
			}
			
			for (String s : si) {
				map.remove(s);
			}
			
			//check only border chars
			for (String s : map.keySet()) {
				String tmp = noBorder(s);
				for (char c : onlyBorder.keySet()) {
					if (tmp.indexOf(c) != -1) {
						fail = true;
						break;
					}
				}
			}
			
			int[] next = new int[26];
			int[] prev = new int[26];
			Arrays.fill(next, -1);
			Arrays.fill(prev, -1);
			
			for (String s : map.keySet()) {
				for (int i = 1; i < s.length(); ++i) {
					if (s.charAt(i) != s.charAt(i-1)) {
						if (next[(int)(s.charAt(i-1) - 'a')] != -1) {
							fail = true;
							break;
						}
						if (prev[(int)(s.charAt(i)-'a')] != -1) {
							fail = true;
							break;
						}
						next[(int)(s.charAt(i-1) - 'a')] = (int)(s.charAt(i)-'a');
						prev[(int)(s.charAt(i)-'a')] = (int)(s.charAt(i-1) - 'a');
					}
				}
			}
			
			int[] comp = new int[26];
			Arrays.fill(comp, -1);
			int cur = 0;
			for (int i = 0; i < 26; ++i) {
				if (comp[i] == -1 && prev[i] == -1 && next[i] != -1) {
					int pos = i;
					comp[i] = cur;
					while (next[pos] != -1) {
						pos = next[pos];
						comp[pos] = cur;
					}
					++cur;
				}
			}
			
			//check cycles
			for (int i = 0; i < 26; ++i) {
				if (comp[i] == -1 && prev[i] != -1) {
					fail = true;
					break;
				}
			}
			
			for (char c : onlyBorder.keySet()) {
				int idx = (int)(c - 'a');
				if (prev[idx] == -1 && next[idx] == -1) {
					++cur;
				}
			}
			
			if (fail) {
				out.println("Case #" + (cs+1) + ": 0");
			}
			else {
				ans = (ans * fac(cur))%MOD;
				out.println("Case #" + (cs+1) + ": " + ans);
			}
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\B.txt")));
		out = new PrintWriter("D:\\BB.txt");
		(new Thread(new B())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}

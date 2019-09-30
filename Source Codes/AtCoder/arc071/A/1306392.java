import java.util.*;

public class Main {
	
	/*
	 * default function
	 * */	
	int ni() {
		return cin.nextInt();
	}
	
	long nl() {
		return cin.nextLong();
	}
	
	String line() {
		return cin.nextLine();
	}
	
	void println(String str) {	
		System.out.println(str);
	}
	
	void print(String str) {
		System.out.print(str);
	}
	
	/*
	 * default variable
	 */
	
	static final int MOD = 1000000007;
	
	Scanner cin = new Scanner(System.in);	
	String  output;
	
	public static void main(String[] args) {			
		new Main().run();						
	}
	
	/* default above */		
	public void run() {
			
		input();
		/* 
		 * start
		 */	
		
		output = solve();
		
		/*
		 * finish
		 */
		
		
		println(output);
			
	}
	/* 
	 * define variable
	 */
	
	int N;
	String[] words;
	
	void input() {
		
		N = ni();
		words = new String[N];
		
		line();
		for (int i = 0; i < N; i ++) {
			words[i] = line();
		}
	}
	
	String solve() {
		
		int[] cnt1 = new int[26];
		int[] cnt2;
		
		//init
		for (char c: words[0].toCharArray()) {
			cnt1[c-'a'] ++;
		}
		
		for (int i = 1; i < N; i ++) {
			
			cnt2 = new int[26];
			for (char c: words[i].toCharArray()) {
				cnt2[c-'a'] ++;
			}
			
			for (int j = 0; j < 26; j ++) {
				if (cnt1[j] == 0) {
					continue;
				}
				
				cnt1[j] = Math.min(cnt1[j], cnt2[j]);
			}
		}
		
		
		StringBuilder res = new StringBuilder();
		
		for (int i = 0; i < 26; i ++) {
			
			if (cnt1[i] == 0) {
				continue;
			}
			
			for (int j = 0; j < cnt1[i]; j ++) {
				res.append((char)(i +'a'));
			}
		}
		
		return res.toString();
		
	}
	
}
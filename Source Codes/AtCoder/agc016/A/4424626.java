import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		int[] cnt = new int[26];
		for(int i = 0; i < s.length(); i++) {
			int idx = s.charAt(i) - 'a';
			cnt[idx]++;
		}
		int min = 100;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 0) continue;
			char c = (char)(i + 'a');
			String t = s;

			int m = 0;
			for(int j = 0; j < 100; j++) {
				if(check(t, c)) break;
				String w = "";
				m++;
				for(int k = 0; k < t.length() - 1; k++) {
					if(t.charAt(k) == c || t.charAt(k + 1) == c) {
						w += c;
					}else {
						w += t.charAt(k);
					}
				}
				t = w;
			}
			min = Math.min(min, m);
		}
		System.out.println(min);
	}
	static boolean check(String s, char c) {
		for(int i = 0; i < s.length(); i++) {
			if(c != s.charAt(i)) return false;
		}
		return true;
	}
}
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		int l = s.length();

		if(l == 26) {
			int[] p = new int[l];
			for(int i = 0; i < l; i++) {
				p[i] = s.charAt(i) - 'a';
			}
			if(next_permutation(p)) {
				for(int i = 0; i < 26; i++) {
					if(s.charAt(i) - 'a' == p[i]) {
						System.out.print(s.charAt(i));
					}else {
						System.out.println((char)(p[i] + 'a'));
						break;
					}
				}
			}else {
				System.out.println(-1);
			}
		}else {
			int[] a = new int[26];
			for(int i = 0; i < l; i++) {
				a[s.charAt(i) - 'a']++;
			}
			for(int i = 0; i < 26; i++) {
				if(a[i] == 0) {
					System.out.print(s);
					System.out.println((char)(i + 'a'));
					break;
				}
			}
		}
	}
	static boolean next_permutation(int[] p) {
		for(int a = p.length - 2; a >= 0; --a) {
			if(p[a] < p[a + 1]) {
				for(int b = p.length - 1;; --b) {
					if(p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for(++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
				}
			}
		}
		return false;
	}
}
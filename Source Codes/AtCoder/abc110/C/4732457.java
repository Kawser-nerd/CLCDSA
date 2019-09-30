import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		int n = S.length();
		char[] s = S.toCharArray();
		char[] t = T.toCharArray();
		int[] a = new int[26];
		int[] b = new int[26];
		for(int i = 0; i < n; i ++) {
			a[s[i]-97] += 1;
			b[t[i]-97] += 1;
		}
		Arrays.sort(a);
		Arrays.sort(b);
		for(int i = 0; i < 26; i++) {
			if(a[i] != b[i]) {
				System.out.println("No");
				break;
			}
			else if(i == 25)
				System.out.println("Yes");
		}
	}

}
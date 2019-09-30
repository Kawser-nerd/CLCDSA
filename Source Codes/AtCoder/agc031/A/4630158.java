import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int[] alp = new int[26];
		for (int i = 0; i < n; i++) {
			alp[s.charAt(i) - 'a']++;
		}
		long mod = 1000000007;
		long count = 1;
		for (int i = 0; i < 26; i++) {
			count = count * (alp[i] + 1) % mod;
		}
		System.out.println(count - 1);
	}
}
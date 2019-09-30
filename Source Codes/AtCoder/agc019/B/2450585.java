import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = s.length();
		int[] count = new int[26];
		for (int i=0;i<n;i++) {
			count[s.charAt(i)-'a']++;
		}

		long ans = (long)n*(n-1)/2;
		for (int i=0;i<26;i++) {
			ans -= ((long)count[i]*(count[i]-1)/2);
		}
		System.out.println(ans+1);
	}

}
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String t = sc.next();
		sc.close();
		int n = t.length();
		if(n == 2) {
			if(t.charAt(0) == t.charAt(1)) {
				System.out.println("1 2");
			}else {
				System.out.println("-1 -1");
			}
			System.exit(0);
		}
		for(int i = 0; i < n - 2; i++) {
			char c0 = t.charAt(i);
			char c1 = t.charAt(i + 1);
			char c2 = t.charAt(i + 2);
			int[] k = new int[26];
			k[(int)(c0 - 'a')]++;
			k[(int)(c1 - 'a')]++;
			k[(int)(c2 - 'a')]++;
			Arrays.sort(k);
			if(k[25] == 2) {
				System.out.printf("%d %d\n", i + 1, i + 3);
				System.exit(0);
			}
		}
		System.out.println("-1 -1");
	}
}
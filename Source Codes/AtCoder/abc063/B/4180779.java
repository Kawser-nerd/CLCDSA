import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String S = sc.next();
		int[] map = new int[26];
		for (char c: S.toCharArray()) {
			map[c-'a']++;
			if (map[c-'a'] > 1) {
				System.out.println("no");
				return;
			}
		}
		
		System.out.println("yes");
	}
}
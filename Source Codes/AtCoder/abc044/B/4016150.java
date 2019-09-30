import java.util.*;

public class Main {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int[] arr = new int[26];
		for (int i = 0; i < s.length(); i++) {
			arr[s.charAt(i) - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 != 0) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
}
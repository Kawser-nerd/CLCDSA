import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = s.length();
		for(int i = 0 ; i < n / 2 ; i++) {
			if(s.charAt(i) != s.charAt(n - 1 - i)) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}
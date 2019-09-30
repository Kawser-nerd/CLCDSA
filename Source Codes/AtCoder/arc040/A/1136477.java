import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int r = 0;
		int b = 0;
		for (int i = 0;i < n;i++) {
			String s = sc.next();
			for (int j = 0;j < n;j++) {
				char c = s.charAt(j);
				if (c=='R') r++;
				if (c=='B') b++;
			}
		}
		if (r>b) System.out.println("TAKAHASHI");
		if (r<b) System.out.println("AOKI");
		if (r==b) System.out.println("DRAW");
	}
}
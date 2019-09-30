import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h1 = sc.nextInt();
		int w1 = sc.nextInt();
		int h2 = sc.nextInt();
		int w2 = sc.nextInt();
		if (h1 == h2 || w1 == w2 || h1 == w2 || w1 == h2) {
			System.out.print("YES");
		} else {
			System.out.print("NO");
		}
	}
}
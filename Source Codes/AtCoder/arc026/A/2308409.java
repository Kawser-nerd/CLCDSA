import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (i <= 5)
				c += b;
			else
				c += a;
		}
		System.out.println(c);
	}
}
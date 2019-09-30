import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		String ans = "";
		ans = s.substring(0, a) + "\"" + s.substring(a, b) + "\"" + s.substring(b, c) + "\"" + s.substring(c, d) + "\"" + s.substring(d);
		System.out.println(ans);
	}
}
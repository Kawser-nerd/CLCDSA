import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		String t = scan.next();

		String total = s+t;
		int ans = Integer.parseInt(total)*2;

		System.out.println(ans);
	}
}
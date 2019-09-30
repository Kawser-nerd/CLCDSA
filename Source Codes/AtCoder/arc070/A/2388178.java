import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int ans = 0;
		int cout = 0;
		while(ans < x) {
			cout++;
			ans += cout;
		}
		System.out.println(cout);
	}
}
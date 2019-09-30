import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int a = (n - 1 + 2 - 1) / 2;
		if(a >= k) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}
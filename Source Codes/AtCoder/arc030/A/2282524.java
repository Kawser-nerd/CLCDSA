import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int point = 1;
		if(k <= point&&n >= point) {
			System.out.println("YES");
			return;
		}
		n--;
		if(k <= point&&n >= point) {
			System.out.println("YES");
			return;
		}
		while(n > 0) {
			n--;
			point++;
			if(k <= point&&n >= point) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}
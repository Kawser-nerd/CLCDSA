import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n==1) {
			System.out.println("BOWWOW");
			return;
		}
		long a = 0;
		for(int i = n; i >= 0; i--) a += i;
		for(int i = 2; i <= Math.sqrt(a); i++) {
			if(a % i == 0) {
				System.out.println("BOWWOW");
				return;
			}
		}
		System.out.println("WANWAN");
	}
}
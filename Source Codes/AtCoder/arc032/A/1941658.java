import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = 0;
		for(int i = 1 ; i <= n ; i++) {
			a += i;
		}
		if(a == 1) {
			System.out.println("BOWWOW");
			return;
		}
		for(int i = 2 ; i * i <= a ; i++) {
			if(a % i == 0) {
				System.out.println("BOWWOW");
				return;
			}
		}
		System.out.println("WANWAN");
	}
}
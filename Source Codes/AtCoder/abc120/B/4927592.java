import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		for(int i = Math.max(a, b); i > 0; i--) {
			if(a %i != 0 || b % i != 0)
				continue;
			
			if(--k == 0) {
				System.out.println(i);
				return;
			}
		}
	}
}
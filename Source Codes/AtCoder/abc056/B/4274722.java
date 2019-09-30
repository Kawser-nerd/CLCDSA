import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int w = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		if(Math.max(a, b) - (Math.min(a, b)+w) > 0) {
			System.out.println(Math.max(a, b) - (Math.min(a, b)+w));
		}else {
			System.out.println(0);
		}
	}
}
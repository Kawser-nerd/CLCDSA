import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		sc.close();
		if(N < A) System.out.println("Broys");
		if((B - A) % 2 == 0) {
			System.out.println("Alice");
		}else {
			System.out.println("Borys");
		}
	}
}
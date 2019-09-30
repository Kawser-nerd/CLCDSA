import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		if(A + B == C) {
			System.out.println(A + 2 *B);
		}else if(A + B < C) {
			System.out.println(A + 2 * B + 1);
		}else {
			System.out.println(B + C);
		}
	}
}
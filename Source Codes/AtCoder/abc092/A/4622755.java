import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int C = reader.nextInt();
		int D = reader.nextInt();
		int ans = Math.min(A, B) + Math.min(C, D) ;
		reader.close();
		System.out.print(ans);
	}
}
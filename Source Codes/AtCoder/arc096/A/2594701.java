import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int res = Integer.MAX_VALUE;
		for (int i=0; i<=Math.max(X, Y); i++){
			int total = i*(2*C) + A*Math.max(0, X-i) + B*Math.max(0, Y-i);
			res = Math.min(res, total);
		}
		System.out.println(res);
	}
}
import java.util.Scanner;
public class Main {
	static int N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		int a=sc.nextInt();
		System.out.println(Math.min(Math.abs(N-a),10-Math.max(N, a)+Math.min(N, a)));
	}
}
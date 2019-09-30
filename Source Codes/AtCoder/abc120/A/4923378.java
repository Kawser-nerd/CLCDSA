import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		int ans = B/A;
		if(ans > C) {
			ans = C;
		}

		System.out.println(ans);


	}
}
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int a = reader.nextInt();
		int b = reader.nextInt();
		int K = reader.nextInt();
		List<Integer> P = new ArrayList<Integer>();
		String ans = "YES";
		for (int i = 0; i < K; i++) {
			int num = reader.nextInt();
			if (P.contains(num) || num == a || num == b) {
				ans = "NO";
			}
			P.add(num);
		}
		System.out.println(ans);
		reader.close();
	}
}
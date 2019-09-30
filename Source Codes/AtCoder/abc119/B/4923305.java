import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double sum = 0;

		for(int i=0; i<N; i++) {
			double x = sc.nextDouble();
			if ("JPY".equals(sc.next())) {
				sum += x;
			} else {
				sum += x * 380000;
			}
		}

		System.out.println(sum);


	}
}
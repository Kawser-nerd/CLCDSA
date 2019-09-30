import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		int n, a, b;
		try (Scanner sc = new Scanner(System.in)) {
			n = Integer.parseInt(sc.next());
			a = Integer.parseInt(sc.next());
			b = Integer.parseInt(sc.next());
		}

		int total = 0;
		for (int i=1; i<=n; i++) {
			int sum = i/10000 + (i%10000)/1000 + (i%1000)/100 + (i%100)/10 + (i%10);
			if (a <= sum && sum <= b) {
				total += i;
			}
		}
		System.out.println(total);
	}
}
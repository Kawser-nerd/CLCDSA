import java.util.Scanner;

public class Surprising {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for (int trial = 1; trial <= cases; trial++) {
			System.out.print("Case #" + trial + ": ");
			int googlers = scan.nextInt();
			int surprising = scan.nextInt();
			int p = scan.nextInt();
			int count = 0;
			for (int i = 0; i < googlers; i++) {
				int totScore = scan.nextInt();
				if ((totScore + 2) / 3 >= p)
					count++;
				else if (Math.min((totScore + 4) / 3, totScore) >= p && surprising > 0) {
					surprising--;
					count++;
				}
			}
			System.out.println(count);
		}
	}
}

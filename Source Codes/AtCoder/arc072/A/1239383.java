import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveC();
	}

	private void solveC() {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long oddPlusSum = 0;
		long evenPlusSum = 0;
		long oddPlusAns = 0;
		long evenPlusAns = 0;
		for (int i = 0; i < n; i++) {
			long tmp = sc.nextLong();
			oddPlusSum += tmp;
			evenPlusSum += tmp;
			if (i % 2 == 0) {
				if (oddPlusSum >= 0) {
					oddPlusAns += oddPlusSum + 1;
					oddPlusSum = -1;
				}
				if (evenPlusSum <= 0) {
					evenPlusAns += 1 - evenPlusSum;
					evenPlusSum = 1;
				}
			} else {
				if (oddPlusSum <= 0) {
					oddPlusAns += 1 - oddPlusSum;
					oddPlusSum = 1;
				}
				if (evenPlusSum >= 0) {
					evenPlusAns += evenPlusSum + 1;
					evenPlusSum = -1;
				}
			}
		}
		if (evenPlusAns < oddPlusAns) {
			System.out.println(evenPlusAns);
		} else {
			System.out.println(oddPlusAns);
		}
	}
}
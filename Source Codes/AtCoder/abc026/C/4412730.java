import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] b = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			b[i] = sc.nextInt();
		}
		int[] salary = new int[n + 1];
		for (int i = n; i >= 1; i--) {
			ArrayList<Integer> bukaSalary = new ArrayList<>();
			for (int j = 2; j <= n; j++) {
				if (b[j] == i) {
					bukaSalary.add(salary[j]);
				}
			}
			if (bukaSalary.size() == 0) {
				salary[i] = 1;
			} else if (bukaSalary.size() == 1) {
				salary[i] = bukaSalary.get(0) * 2 + 1;
			} else {
				Collections.sort(bukaSalary);
				salary[i] = bukaSalary.get(0) + bukaSalary.get(bukaSalary.size() - 1) + 1;
			}
		}
		System.out.println(salary[1]);
 	}
}
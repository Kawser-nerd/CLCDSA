import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		List<Integer> aDivisor = new ArrayList<>();
		List<Integer> bDivisor = new ArrayList<>();
		for(int i = 1; i <= a; i++) {
			if(a%i==0) {
				aDivisor.add(i);
			}
		}
		for(int i = 1; i <= b; i++) {
			if(b%i==0) {
				bDivisor.add(i);
			}
		}
		// ??
		Collections.sort(aDivisor, Collections.reverseOrder());
		Collections.sort(bDivisor, Collections.reverseOrder());
		int ans = 0;
		if(aDivisor.size() < bDivisor.size()) {
			ans =findKthDivisor(bDivisor, aDivisor, k);
		} else {
			ans =findKthDivisor(aDivisor, bDivisor, k);
		}
		System.out.println(ans);

	}
	public static int findKthDivisor(List<Integer> manyDivisor, List<Integer> fewDivisor, int k) {
		int count = 0;
		for(int div : fewDivisor) {
			if(manyDivisor.contains(div)) {
				count++;
				if(count == k) {
					return div;
				}
			}
		}
		return 0;
	}
}
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();

		List<Integer> TList = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			TList.add(sc.nextInt());
		}
		Collections.sort(TList);

		int cnt = 0;
		int bus = 0;
		int start = TList.get(0);

		for (int i : TList) {
			if (cnt < C && i <= start + K) {
				cnt ++;
				continue;
			}
			cnt = 1;
			start = i;
			bus++;
		}
		bus++;
		System.out.println(bus);
	}
}
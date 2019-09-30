import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		++N;
		ArrayDeque<Integer> deque = new ArrayDeque<>();
		int curVal = 1;
		ArrayList<Integer> lis = new ArrayList<>();
		while (N > 0) {
			if (N % 2 == 0) {
				lis.add(0);
			} else {
				lis.add(1);
			}
			N /= 2;
		}
		for (int i = lis.size() - 2; i >= 0; --i) {
			deque.addLast(curVal);
			if (lis.get(i) == 1) {
				++curVal;
				deque.addFirst(curVal);
			}
			++curVal;

		}
		--curVal;
		System.out.println(curVal * 2);
		for (int i = 0; i < curVal; ++i) {
			System.out.print(deque.pollFirst() + " ");
		}
		for (int i = 1; i <= curVal; ++i) {
			System.out.print(i + (i == curVal ? "\n" : " "));
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
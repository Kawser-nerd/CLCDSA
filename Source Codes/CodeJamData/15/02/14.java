import java.io.File;
import java.io.PrintStream;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	static final int LIMIT = 1000;

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int dinerNum = in.nextInt();
			int[] diners = new int[dinerNum];
			for (int i = 0; i < diners.length; i++) {
				diners[i] = in.nextInt();
			}

			int lower = 0;
			int upper = LIMIT;
			int time = -1;
			while (lower <= upper) {
				int middle = (lower + upper) / 2;
				if (canFinish(diners, middle)) {
					time = middle;
					upper = middle - 1;
				} else {
					lower = middle + 1;
				}
			}
			out.println(time);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static boolean canFinish(int[] diners, int timeLeft) {
		for (int eatTime = 1; eatTime <= timeLeft; eatTime++) {
			if (canFinish(diners, timeLeft, eatTime)) {
				return true;
			}
		}
		return false;
	}

	static boolean canFinish(int[] diners, int timeLeft, int eatTime) {
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>((x, y) -> y - x);
		for (int diner : diners) {
			pq.offer(diner);
		}

		while (timeLeft > eatTime) {
			if (pq.peek() <= eatTime) {
				return true;
			}

			int head = pq.poll();
			int part1 = Math.min(head / 2, eatTime);
			int part2 = head - part1;
			pq.offer(part1);
			pq.offer(part2);

			timeLeft--;
		}
		return pq.peek() <= eatTime;
	}
}

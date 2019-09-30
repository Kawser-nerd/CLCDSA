package round1a;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class C2 {
	
	private static class Task implements Callable<String> {
		int N;
		long[] x, y;
		
		public Task(Scanner sc) {
			N = sc.nextInt();
			x = new long[N];
			y = new long[N];
			for (int i = 0; i < N; i++) {
				x[i] = sc.nextLong();
				y[i] = sc.nextLong();
			}
		}
		

		@Override
		public String call() throws Exception {
			int[] best = new int[N];
			for (int i = 0; i < N; i++) best[i] = Math.max(0, N-3);
			for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) {
				int left = 0, right = 0;
				for (int k = 0; k < N; k++) {
					long d = (x[k] - x[i]) * (y[j] - y[i]) - (y[k] - y[i]) * (x[j] - x[i]);
					if (d < 0) left++;
					if (d > 0) right++;
				}
				best[i] = Math.min(best[i], Math.min(left, right));
				best[j] = Math.min(best[j], Math.min(left, right));
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < best.length; i++) {
				sb.append(best[i]).append("\n");
			}
			return sb.toString();
		}
		
	}
	
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		ExecutorService executorService = Executors.newFixedThreadPool(8);
		List<Future<String>> answers = new ArrayList<Future<String>>();
		for (int caze = 1; caze <= cases; caze++) {
			answers.add(executorService.submit(new Task(sc)));
		}
		for (int caze = 1; caze <= cases; caze++) {
			System.out.println("Case #" + caze + ":");
			System.out.print(answers.get(caze - 1).get());
		}
		executorService.shutdown();
		executorService.awaitTermination(1, TimeUnit.HOURS);
	}

}

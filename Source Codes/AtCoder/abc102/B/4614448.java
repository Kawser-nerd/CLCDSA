import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		Input input = new Input();
		final Data l = input.readLine();
		final int n = l.col[0];
		Queue<Integer> q = input.getColQueue();
		input.close();

		// ----- main -----
		int min = q.poll();
		int max = min;
		while(!q.isEmpty()) {
			max = q.poll();
		}

		System.out.println(max - min);
	}

	/* --------------------------------------------------------------------
	 * inupt class
	 * -------------------------------------------------------------------- */
	static class Input {

		public BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		public void close() throws Exception {
			input.close();
		}

		public Data readLine() throws Exception {
			return new Data(input.readLine().split(" "));
		}

		public Queue<Integer> getColQueue() throws Exception {

			Data d = readLine();
			PriorityQueue<Integer> q;
			q = new PriorityQueue<>( (a,b) -> a - b);	// ??
			for(int i=0; i < d.col.length; i++) {
				q.offer(d.col[i]);
			}
			return q;
		}
	}
	/* --------------------------------------------------------------------
	 * data class
	 * -------------------------------------------------------------------- */
	static class Data{
		public int[] col;
		public Data(String[] values) {
			col = new int[values.length];
			for(int i=0; i < values.length; i++) {
				col[i] = Integer.parseInt(values[i]);
			}
		}
	}
}
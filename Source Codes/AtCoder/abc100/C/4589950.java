import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		Input input = new Input();
		final Data l = input.readLine();
		Queue<Integer> q = input.getColQueue();
		input.close();

		// ----- main -----
		int ans = 0;
		while(!q.isEmpty()) {
			int d = q.poll();
			while(d%2==0) {
				ans++;
				d /= 2;
			}
		}

		System.out.println(ans);
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

		public Queue<Data> getDataQueue(int num) throws Exception {

			Queue<Data> q;
			q = new ArrayDeque<>();
//			data = new PriorityQueue<>( (a,b) -> a.col[0] - b.col[0]);	// ??


			for(int i=0; i < num; i++) {
				q.offer(readLine());
			}
			return q;
		}

		public Queue<Integer> getColQueue() throws Exception {

			Data d = readLine();
			Queue<Integer> q;
			q = new ArrayDeque<>();
//			queue = new PriorityQueue<>( (a,b) -> a.col[0] - b.col[0]);	// ??
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
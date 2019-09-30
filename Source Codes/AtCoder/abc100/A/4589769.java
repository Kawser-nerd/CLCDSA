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
		final int A = l.col[0];
		final int B = l.col[1];
		input.close();

		// ----- main -----
		System.out.println((A <= 8 && B <= 8)? "Yay!" : ":(");
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

		public Queue<Integer> getColQueue(Data data) {

			Queue<Integer> q;
			q = new ArrayDeque<>();
//			queue = new PriorityQueue<>( (a,b) -> a.col[0] - b.col[0]);	// ??
			for(int i=0; i < data.col.length; i++) {
				q.offer(data.col[i]);
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
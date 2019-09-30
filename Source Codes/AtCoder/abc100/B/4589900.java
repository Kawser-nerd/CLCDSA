import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		Input input = new Input();
		final Data l = input.readLine();
		final int D = l.col[0];
		final int N = l.col[1];

		// ----- main -----
		System.out.print((int)Math.pow(100, D)*(N==100?N+1:N));
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
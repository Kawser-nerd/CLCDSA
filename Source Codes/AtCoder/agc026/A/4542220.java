import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) {

		try(BufferedReader input = new BufferedReader(new InputStreamReader(System.in))) {

			// ----- input -----
			final int line1[] = InputUtil.readLine(input.readLine());
			final int col = line1[0];

			//  ----- data -----
			Queue<Data> data = InputUtil.getCollection(input, col);

			// ----- main -----
			int cnt = 0;
			int pre = 0;
			while(!data.isEmpty()) {
				Data d = data.poll();
				if(pre == d.a) {
					cnt++;
					pre = -1;
				} else {
					pre = d.a;
				}
			}

			System.out.println(cnt);

		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}

/* --------------------------------------------------------------------
* inupt class
* -------------------------------------------------------------------- */
class InputUtil {

	public static int[] readLine(String line) {

		String[] vals = line.split(" ");
		int[] data = new int[vals.length];
		int i = 0;

		try {
			for(String val : vals) {
				data[i++] = Integer.parseInt(val);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return data;
	}

	public static Queue<Data> getCollection(BufferedReader input, int num) {

		// Queue<Data> data = new PriorityQueue<>();	// sort
		Queue<Data> data = new ArrayDeque<>();			// fifo
		try {
			String[] line = input.readLine().split(" ");
			for(int i=0; i < num; i++) {
				data.add(new Data(line[i]));
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return data;
	}
}

/* --------------------------------------------------------------------
* data class
* -------------------------------------------------------------------- */
class Data implements Comparable<Data>{
	int a;

	public Data(String value) {
		this.a = Integer.parseInt(value);
	}

	@Override
	public int compareTo(Data d) {
		return a - d.a;	// ??
//		return d.a - a;		// ??
	}
}
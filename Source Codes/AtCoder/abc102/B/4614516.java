import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		input.readLine();
		String values[] = input.readLine().split(" ");
		input.close();

		// ----- main -----
		int[] ary = new int[values.length];
		for(int i=0; i < values.length; i++) {
			ary[i] = Integer.parseInt(values[i]);
		}
		Arrays.parallelSort(ary);

		System.out.println(ary[ary.length-1] - ary[0]);
	}
}
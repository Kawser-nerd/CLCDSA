import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String n = input.readLine();
		int num = Integer.parseInt(n);
		input.close();

		// ----- main -----
		int w = 0;
		for(int i=0; i < n.length(); i++) {
			w += Character.getNumericValue(n.charAt(i));
		}
		System.out.println(num%w==0?"Yes":"No");
	}
}
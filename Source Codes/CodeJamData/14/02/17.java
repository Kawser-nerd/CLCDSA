import java.io.*;
import java.util.Scanner;

public class CookieClicker_B_Q14 {

	private static final String PROBLEM_NAME = "B-large";

	private static final String INPUT_PATH = PROBLEM_NAME + ".in";
	private static final String OUTPUT_PATH = PROBLEM_NAME + "-Output.txt";

	private final double c;
	private final double f;
	private final double x;


	public CookieClicker_B_Q14(Scanner in) {
		c = in.nextDouble();
		f = in.nextDouble();
		x = in.nextDouble();
	}

	public String solve() {
		double rate = 2.0D;
		double time = 0;

		while (true) {
			double thisTime = time + (x / rate);
			double nextRate = rate + f;
			double nextTime = time + c / rate + x / nextRate;
			if (nextTime > thisTime) {
				break;
			} else {
				time = time + c / rate;
				rate = nextRate;
			}
		}

		return Double.toString(time + (x / rate));
	}

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File(INPUT_PATH)) ;
			 BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_PATH)))) {

			int t = in.nextInt();
			for (int i = 1 ; i <= t ; i++) {
				System.out.println("Case #" + i);
				out.write("Case #" + i + ": ");
				out.write(new CookieClicker_B_Q14(in).solve());
				out.newLine();
				out.flush();
			}
		}
	}

}

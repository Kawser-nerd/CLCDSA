import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "F:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();

			double time = 0;
			double speed = 2;
			while (X / speed > C / speed + X / (speed + F)) {
				time += C / speed;
				speed += F;
			}
			time += X / speed;
			out.println(time);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}
}

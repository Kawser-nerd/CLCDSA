import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class D {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "D";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "F:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	@SuppressWarnings("unchecked")
	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int N = in.nextInt();
			ArrayList<Double> naomi = readMesses(in, N);
			ArrayList<Double> ken = readMesses(in, N);

			Collections.sort(naomi);
			Collections.sort(ken);

			int naomiDeceitful = playDeceitful(
					(ArrayList<Double>) naomi.clone(),
					(ArrayList<Double>) ken.clone());
			int naomiWar = playWar((ArrayList<Double>) naomi.clone(),
					(ArrayList<Double>) ken.clone());
			out.println(naomiDeceitful + " " + naomiWar);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static ArrayList<Double> readMesses(Scanner in, int size) {
		ArrayList<Double> messes = new ArrayList<Double>();
		for (int i = 0; i < size; i++) {
			messes.add(in.nextDouble());
		}
		return messes;
	}

	static int playDeceitful(ArrayList<Double> naomi, ArrayList<Double> ken) {
		int naomiDeceitful = 0;
		for (double kenMess : ken) {
			int indexToInsert = -1 - Collections.binarySearch(naomi, kenMess);
			if (indexToInsert == naomi.size()) {
				break;
			}
			naomi.remove(indexToInsert);
			naomiDeceitful++;
		}
		return naomiDeceitful;
	}

	static int playWar(ArrayList<Double> naomi, ArrayList<Double> ken) {
		int naomiWar = 0;
		for (double naomiMess : naomi) {
			int indexToInsert = -1 - Collections.binarySearch(ken, naomiMess);
			if (indexToInsert == ken.size()) {
				ken.remove(0);
				naomiWar++;
			} else {
				ken.remove(indexToInsert);
			}
		}
		return naomiWar;
	}
}

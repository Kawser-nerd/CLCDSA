import java.io.*;
import java.util.HashSet;
import java.util.Scanner;

public class MagicTrick_A_Q14 {

	private static final String PROBLEM_NAME = "A-small-attempt0";

	private static final String INPUT_PATH = PROBLEM_NAME + ".in";
	private static final String OUTPUT_PATH = PROBLEM_NAME + "-Output.txt";

	private final int[][] layout1 = new int[4][4];
	private final int answer1;
	private final int[][] layout2 = new int[4][4];
	private final int answer2;

	public MagicTrick_A_Q14(Scanner in) {
		answer1 = in.nextInt();
		for (int i = 0 ; i < 4 ; i++) {
			for (int j = 0 ; j < 4 ; j++) {
				layout1[i][j] = in.nextInt();
			}
		}
		answer2 = in.nextInt();
		for (int i = 0 ; i < 4 ; i++) {
			for (int j = 0 ; j < 4 ; j++) {
				layout2[i][j] = in.nextInt();
			}
		}
	}

	public String solve() {
		HashSet<Integer> possible1 = new HashSet<>();
		HashSet<Integer> possible2 = new HashSet<>();
		for (int i : layout1[answer1 - 1]) {
			possible1.add(i);
		}
		for (int i : layout2[answer2 - 1]) {
			possible2.add(i);
		}

		possible1.retainAll(possible2);

		if (possible1.size() == 0) {
			return "Volunteer cheated!";
		} else if (possible1.size() == 1) {
			return Integer.toString(possible1.iterator().next());
		} else {
			return "Bad magician!";
		}

	}

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File(INPUT_PATH)) ;
			 BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_PATH)))) {

			int t = in.nextInt();
			for (int i = 1 ; i <= t ; i++) {
				System.out.println("Case #" + i);
				out.write("Case #" + i + ": ");
				out.write(new MagicTrick_A_Q14(in).solve());
				out.newLine();
				out.flush();
			}
		}
	}

}

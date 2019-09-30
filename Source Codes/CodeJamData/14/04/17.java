import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class DeceitfulWar_D_Q14 {

	private static final String PROBLEM_NAME = "D-large";

	private static final String INPUT_PATH = PROBLEM_NAME + ".in";
	private static final String OUTPUT_PATH = PROBLEM_NAME + "-Output.txt";

	/*

	Kens strategy:
	if he has no blocks heavier than Naomi's, play his lightest
	otherwise, play the lightest block that is heavier

	Naomi's honest strategy
	light to heavy

	Naomi's deceitful strategy
	go from lightest to heaviest:
	  if it's heavier than his lightest, tell him it's extremely heavy
	  if it's lighter than his lightest, tell him it's slightly lighter than his heaviest

	wrong #1:
	choose lightest block and tell Ken it's slightly lighter than his heaviest
	when her lightest block is heavier than his heaviest, be honest

	 */

	private final double[] nBlocks;
	private final double[] kBlocks;

	public DeceitfulWar_D_Q14(Scanner in) {
		int n = in.nextInt();
		nBlocks = new double[n];
		kBlocks = new double[n];
		for (int i = 0 ; i < n ; i++) {
			nBlocks[i] = in.nextDouble();
		}
		for (int i = 0 ; i < n ; i++) {
			kBlocks[i] = in.nextDouble();
		}
	}

	public String solve() {
		Arrays.sort(nBlocks);
		Arrays.sort(kBlocks);

		int nPointsDW = 0;
		int kLightest = 0;
		for (int i = 0 ; i < nBlocks.length ; i++) {
			if (nBlocks[i] > kBlocks[kLightest]) {
				nPointsDW++;
				kLightest++;
			}
		}



		int nPointsW = 0;
		boolean[] kUsed = new boolean[kBlocks.length];
	outer:
		for (int j = 0 ; j < nBlocks.length ; j++) {
			for (int k = 0 ; k < kBlocks.length ; k++) {
				if (kBlocks[k] > nBlocks[j] && !kUsed[k]) {
					kUsed[k] = true;
					continue outer;
				}
			}
			for (int k = kBlocks.length - 1 ; k >= 0 ; k--) {
				if (!kUsed[k]) {
					kUsed[k] = true;
					nPointsW++;
				}
			}
		}

		return nPointsDW + " " + nPointsW;
	}

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File(INPUT_PATH)) ;
			 BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_PATH)))) {

			int t = in.nextInt();
			for (int i = 1 ; i <= t ; i++) {
				System.out.println("Case #" + i);
				out.write("Case #" + i + ": ");
				out.write(new DeceitfulWar_D_Q14(in).solve());
				out.newLine();
				out.flush();
			}
		}
	}

}

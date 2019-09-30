import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class Main {

	private static Map<Integer, double[]> cache = new  HashMap<Integer, double[]>();
	
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int n = scanner.nextInt();
				int[] sequence = new int[n];
				for (int j = 0; j < n; j++) {
					sequence[j] = scanner.nextInt();
				}
				double prob = 1.0;
				for (int j = 0; j < sequence.length; j++) {
					prob *= n;
					prob *= computeProbability(new int[]{sequence[j], n}, j);
				}

				out.write("Case #" + (i + 1) + ": " + (prob > 1 ? "BAD" : "GOOD") + "\n");
				System.out.println("Test" + (i+1) + " done " + prob);
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}

	private static double computeProbability(int[] values, int resultIndex) {
		int initial = values[0];
		int n = values[1];
		int hash = n * 1000 + initial;
		double[] probArray = cache.get(hash);
		if (probArray == null) {
			probArray = new double[n];
			for (int k = 0; k < n; k++) {
				probArray[k] = 0.0;
			}
			probArray[initial] = 1.0;
            double[] newProbArray = new double[n];
            double[] tmp = null;
	        for (int i = 0; i < n; i++) {
	        	newProbArray[i] = 0;
				for (int j = 0; j < n; j++) {
					if (i != j) {
			        	newProbArray[j] = probArray[j]*(n-1)/n + probArray[i]* 1./n;
					}
		        	newProbArray[i] += probArray[j]* 1./n;
				}
				tmp = newProbArray;
				newProbArray = probArray;
				probArray = tmp;
			}
	        cache.put(hash, probArray);
		}
		return probArray[resultIndex];
	}
}
import java.util.*;
import java.io.*;

public class Rd1ac {

    public static void main (String[] args) {

		Scanner in = new Scanner(System.in);

		int count = in.nextInt();

		double[] table = generate_table(1000, 1000000);
	//	double[] table = generate_table(3, 10000);
		double[] probs = new double[count];

		for (int l = 0; l < count; l++) {

			int n = in.nextInt();
			int[] perm = new int[n];
			for (int i = 0; i < n; i++) {
				perm[i] = in.nextInt();
			}

			double prob = probability (perm, table, n);
			if (prob > 1)
				probs[l] = prob - 1.0;
			else
				probs[l] = 1.0 - prob;	
		}

		int[] bigger = new int[count];
		for (int i = 0; i < count; i++) {
			bigger[i] = 0;
			for (int j = 0; j < count; j++) {
				if (i != j && probs[i] < probs[j])
					bigger[i] = bigger[i] + 1;
			}
		}
		int best = 0;
		double middle = 0.0;
		for (int i = 0; i < count; i++) {
			if (bigger[i] < count/2 && bigger[i] > best) {
				best = bigger[i];
				middle = probs[i];
			}
		}

		for (int i = 0; i < count; i++) {
			if (probs[i] > middle)
				System.out.println("Case #" + (i+1) + ": BAD");
			else
				System.out.println("Case #" + (i+1) + ": GOOD");
		}

	}



	public static double probability ( int[] perm, double[] table, int size ) {
		double prob = 1.0;
		for (int i = 0; i < size; i++) {
			prob = prob * table[size*i + 
				perm[i]];
		}
		return prob;
	}

	public static double[] generate_table (int size, int times) {

		int[] table = new int[size*size];
		for (int i = 0; i < size*size; i++)
			table[i] = 0;

		Random r = new Random();
		int[] array = new int[size];

		for (int l = 0; l < times; l++) {
			for (int i = 0; i < size; i++)
				array[i] = i;
			for (int i = 0; i < size; i++) {
				int j = r.nextInt(size);
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			for (int i = 0; i < size; i++)
				table[i*size + array[i]] += 1;

		}
		double[] final_table = new double[size*size];
		for (int i = 0; i < size*size; i++)
			final_table[i] = (table[i]*1.0 * size)/(times * 1.0);
		return final_table;
	}

}

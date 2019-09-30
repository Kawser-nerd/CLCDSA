import java.io.*;
import java.util.*;

public class A2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n = input.nextInt();
		for (int x = 0; x < n; x++) {
			int numberOfIngredients = input.nextInt();
			int numberOfPackages = input.nextInt();
			double[] amountPerPack = new double[numberOfIngredients];
			for (int a = 0; a < numberOfIngredients; a++) {
				amountPerPack[a] = input.nextInt();
			}

			ArrayList<Long>[] ingredients = new ArrayList[numberOfIngredients];
			for (int a = 0; a < numberOfIngredients; a++) {
				ingredients[a] = new ArrayList<Long>();
			}

			for (int a = 0; a < numberOfIngredients; a++) {
				for (int b = 0; b < numberOfPackages; b++) {
					ingredients[a].add(input.nextLong());
				}
				Collections.sort(ingredients[a]);
			}

			int numberOfMix = 1;
			int goodMix = 0;
			lbl: while (numberOfMix < 2 * 1E6) {
				ArrayList<Integer> idx = null;
				for (int a = 0; a < numberOfIngredients; a++) {
					boolean found = false;
					int num = 0;
					for (long i : ingredients[a]) {
						if (isInRange(i, numberOfMix * amountPerPack[a])) {
							if(idx == null){
								idx = new ArrayList<Integer>();
							}
							idx.add(num);
							found = true;
							break;
						}
						num++;
					}
					if (found == false) {
						numberOfMix++;
						continue lbl;
					}
				}
				goodMix++;
				for (int a = 0; a < numberOfIngredients; a++) {
					ingredients[a].remove((int)idx.get(a));
				}
			}
			System.out.println("Case #" + (x + 1) + ": " + goodMix);
		}
	}

	private static boolean isInRange(long i, double d) {
		double min = d*0.9*.999999999999;
		double max = d*1.1*1.000000000001;
		// TODO Auto-generated method stub
		return min <= i && max >= i;
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readNextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}

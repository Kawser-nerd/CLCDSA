package b1;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("C-small.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("c-small.out")));
		int n = sc.nextInt();

		for (int T = 1; n-- > 0; T++) {
			int N = sc.nextInt();
			int total = 10;
			int maxHik = 0;
			int[][] rawHikers = new int[N][3];
			for (int i = 0; i < N; i++) {
				rawHikers[i][0] = sc.nextInt();
				rawHikers[i][2] = sc.nextInt();
				rawHikers[i][1] = sc.nextInt();
				maxHik += rawHikers[i][2];
			}

			int[][] hikers = new int[maxHik][2];
			int currentN = 0;
			int insideN = 0;
			for (int i = 0; i < maxHik; i++) {
				if (insideN < rawHikers[currentN][2]) {
					hikers[i][0] = rawHikers[currentN][0];
					hikers[i][1] = rawHikers[currentN][1] + insideN++;
				} else {
					currentN++;
					insideN = 0;
					i--;
				}
			}

//			sort(hikers, 0, hikers.length);

			for (int i = 0; i < maxHik; i++) {
				int currentTotal = 0;
				double time = (double)((double) hikers[i][1] * (360 - hikers[i][0]))/360.0 + 0.000001 ;
				for (int j = 0; j < maxHik; j++) {
					double nbTurn = (double) time / (double) hikers[j][1]
							+ (double) hikers[j][0] / 360.0;
					if (nbTurn > 1) {
						currentTotal += nbTurn - 1;
					} else {
						currentTotal++;
					}
				}
				if(total > currentTotal) {
					total = currentTotal;
				}
			}

			out.println("Case #" + T + ": " + total);
			System.out.println("Case #" + T + ": " + total);
		}
		out.flush();
	}

	private static void sort(int[][] hikers, int begin, int end) {
		if (end - begin < 2)
			return;
		int middle = (begin + end) / 2;
		for (int i = begin; i < middle; i++) {
			if (hikers[i][1] > hikers[middle][1]) {
				swap(hikers, i, middle);
				swap(hikers, i, --middle);
			}
		}
		for (int i = end - 1; i > middle; i--) {
			if (hikers[i][1] < hikers[middle][1]) {
				swap(hikers, middle, i);
				swap(hikers, ++middle, i);
			}
		}
		sort(hikers, begin, middle);
		sort(hikers, middle, end);

	}

	private static void swap(int[][] hikers, int i, int j) {
		// TODO Auto-generated method stub
		int temp0 = hikers[i][0];
		int temp1 = hikers[i][1];
		hikers[i][0] = hikers[j][0];
		hikers[i][1] = hikers[j][1];
		hikers[j][0] = temp0;
		hikers[j][1] = temp1;
	}
}
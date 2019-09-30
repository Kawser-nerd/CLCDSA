import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int n = scanner.nextInt();
				int[][] relations = new int[n][n];
				for (int j = 0; j < n-1; j++) {
					int v1 = scanner.nextInt();
					int v2 = scanner.nextInt();
					relations[v1-1][v2-1] = 1;
					relations[v2-1][v1-1] = 1;
				}
				int min = 10000;
				for (int j = 0; j < n; j++) {
					min = Math.min(min, checkForVertex(relations, j));
				}
				out.write("Case #" + (i + 1) + ": " + min + "\n");
				out.flush();
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}

	private static int[] checkForVertex(int[][] relations, int vertex, int parent) {
		List<Integer> list = new ArrayList<Integer>();
		int dead = 0;
		int live = 1;
		for (int i = 0; i < relations.length; i++) {
			if (relations[vertex][i] == 1 && i != parent) {
				int[] res = checkForVertex(relations, i, vertex);
				dead += res[0];
				list.add(res[1]);
			}
		}
		Collections.sort(list);
		if (list.size() == 0) {
			return new int[]{0, 1};
		}
		else if (list.size() == 1) {
			return new int[]{dead + list.get(0), live};
		}
		else {
			for (int i = 0; i < list.size() - 2; i++) {
				dead += list.get(i);
			}
			for (int i = list.size() - 2; i < list.size(); i++) {
				live += list.get(i);
			}
			return new int[]{dead, live};
		}
	}

	private static int checkForVertex(int[][] relations, int vertex) {
		return checkForVertex(relations, vertex, -1)[0];
	}
}
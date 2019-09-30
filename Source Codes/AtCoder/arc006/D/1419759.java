import java.io.*;
import java.util.*;
import java.awt.*;

// http://arc006.contest.atcoder.jp/tasks/arc006_4
public class Main
{
	public static final int TEMPLATE_SIZE = 7;

	private static void create_sample() throws IOException {
		String outputFileName = "./input7.txt";
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName));
		writer.write("1000 1000\n");
		StringBuilder sb0 = new StringBuilder();
		StringBuilder sb6 = new StringBuilder();
		for (int i = 0; i < 1000; i++) {
			sb0.append('.');
			sb6.append('.');
		}

		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		StringBuilder sb3 = new StringBuilder();
		StringBuilder sb4 = new StringBuilder();
		StringBuilder sb5 = new StringBuilder();
		for (int i = 0; i < 141; i++) {
			sb1.append("...o...");
			sb2.append("..o.o..");
			sb3.append(".o...o.");
			sb4.append(".ooooo.");
			sb5.append(".o...o.");
		}

		sb1.append(".........o...");
		sb2.append("........o.o..");
		sb3.append(".......o...o.");
		sb4.append(".......ooooo.");
		sb5.append(".......o...o.");

		for (int i = 0; i < 142; i++) {
			writer.write(sb0.toString() + "\n");
			writer.write(sb1.toString() + "\n");
			writer.write(sb2.toString() + "\n");
			writer.write(sb3.toString() + "\n");
			writer.write(sb4.toString() + "\n");
			writer.write(sb5.toString() + "\n");
			writer.write(sb6.toString() + "\n");
		}
		writer.write(sb0.toString() + "\n");
		writer.write(sb0.toString() + "\n");
		writer.write(sb0.toString() + "\n");
		writer.write(sb0.toString() + "\n");
		writer.write(sb0.toString() + "\n");
		writer.write(sb0.toString() + "\n");
		writer.close();
	}

	public static void main(String args[]) throws IOException {
		//create_sample();
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

		String tokens[] = r.readLine().split(" ");
		int H = Integer.valueOf(tokens[0]).intValue();
		int W = Integer.valueOf(tokens[1]).intValue();

		BitSet matrix[] = new BitSet[H];
		BitSet visited[] = new BitSet[H];
		for (int i = 0; i < H; i++) {
			matrix[i] = new BitSet(W);
			visited[i] = new BitSet(W);

			String line = r.readLine();
			for (int j = 0; j < W; j++) {
				if (line.charAt(j) == 'o')
					matrix[i].set(j);
			}
		}
		/*
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				System.out.print(matrix[i].get(j) ? 'o' : '.');
			}
			System.out.println();
		}
		*/

		int match_cnt_a = 0;
		int match_cnt_b = 0;
		int match_cnt_c = 0;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (!matrix[h].get(w) || visited[h].get(w))
					continue;

				boolean found = true;
				int unit;
				for (unit = 142; unit > 0; unit--) {
					found = true;
					for (int i = 0; i < unit; i++) {
						for (int j = 0; j < unit; j++) {
							if (!matrix[h + i].get(w + j)) {
								found = false;
								break;
							}
							if (!found)
								break;
						}
						if (!found)
							break;
					}
					if (found)
						break;
				}
				//System.out.println(unit);
				LinkedList<Point> list = new LinkedList<Point>();
				list.addLast(new Point(h, w));
				visited[h].set(w);
				int cnt = 1;
				while (!list.isEmpty()) {
					Point point = list.pollFirst();

					for (int i = point.x - 1; i < point.x + 2; i++) {
						for (int j = point.y - 1; j < point.y + 2; j++) {
							if (!matrix[i].get(j) || visited[i].get(j))
								continue;
							cnt++;
							list.addLast(new Point(i, j));
							visited[i].set(j);
						}
					}
				}
				// A = 12, B = 16, C = 11
				//System.out.println(cnt);
				int num = cnt / (unit * unit);
				switch (num) {
				case 12:
					match_cnt_a++;
					break;
				case 16:
					match_cnt_b++;
					break;
				case 11:
					match_cnt_c++;
					break;
				}
			}
		}
		System.out.println(match_cnt_a + " " + match_cnt_b + " " + match_cnt_c);
	}
}
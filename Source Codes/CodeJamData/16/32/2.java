import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

// B
public class Main {
	public static void main(String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("B-large.out"));
		
		int amountOfTasks = sc.nextInt();
		for (int task = 1; task <= amountOfTasks; task++) {
			int B = sc.nextInt();
			long M = Long.parseLong(sc.next());
			
			long max = (long)Math.pow(2,B-2);
			if (max < M) {
				String solution = "Case #" + task + ": IMPOSSIBLE";
				System.out.println(solution);
				out.println(solution);
			} else {
				int point = 2;
				while(((long)Math.pow(2,point-2)) <= M) {
					point++;
				}
				point--;
				int[][] field = new int[B][B];
				for (int i = 0; i < point-1; i++) {
					for (int j = i+1; j < point; j++) {
						field[i][j] = 1;
					}
				}
				int column = B-1;
				int row = point;
				while(row > 0) {
					long val = (long)Math.pow(2, row-1);
					if (M/val == 1) {
						field[row][column] = 1;
						M -= val;
					}
					row--;
				}
				if (M == 1) {
					field[0][column] = 1;
				}
				field[B-1][B-1] = 0;
				
				String solution = "Case #" + task + ": POSSIBLE";
				System.out.println(solution);
				out.println(solution);
				printArray(out, field);
			}
		}
		
		out.close();
		sc.close();
	}
	
	private void printArray(PrintWriter out, int[][] array) {
		for (int i = 0; i < array.length; i++) {
			String s = "";
			for (int j = 0; j < array[0].length; j++) {
				s += array[i][j];
			}
			System.out.println(s);
			out.println(s);
		}
	}
}
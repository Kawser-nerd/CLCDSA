import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// C
public class Main {
	public static void main(String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("C-large.out"));
		
		int amountOfTasks = sc.nextInt();
		for (int task = 1; task <= amountOfTasks; task++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();
			
			long[] denoms = new long[d];
			for (int i = 0; i < d; i++) {
				denoms[i] = sc.nextLong();
			}
			
			Arrays.sort(denoms);
			int sol = 0;
			long sum = 1;
			int index = 0;
			while(true) {
				if (index < d) {
					if (denoms[index] <= sum) {
						sum += (c*denoms[index]);
						index++;
					} else {
						sum *= (c+1);
						sol++;
					}
				} else {
					sum *= (c+1);
					sol++;
				}
				if (sum > v) break;
			}
			
			String solution = "Case #" + task + ": " + sol;
			System.out.println(solution);
			out.println(solution);
		}
		
		out.close();
		sc.close();
	}
}
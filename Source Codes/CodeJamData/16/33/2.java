import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
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
			int J = sc.nextInt();
			int P = sc.nextInt();
			int S = sc.nextInt();
			int K = sc.nextInt();
			
			int amount = J*P*Math.min(S, K);
			
			String solution = "Case #" + task + ": " + amount;
			System.out.println(solution);
			out.println(solution);
			
			for (int j = 0; j < J; j++) {
				for (int p = 0; p < P; p++) {
					for (int s = 0; s < Math.min(S, K); s++) {
						String sol = (j+1) + " " + (p+1) + " " + (((s+p+j)%S)+1);
						System.out.println(sol);
						out.println(sol);
					}
				}
			}
		}
		
		out.close();
		sc.close();
	}
}
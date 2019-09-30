import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

// A
public class Main {
	public static void main(String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A-large.out"));
		
		int amountOfTasks = sc.nextInt();
		for (int task = 1; task <= amountOfTasks; task++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int w = sc.nextInt();
			
			int total = c/w;
			if (c%w == 0) total--;
			total += w;
			
			if (r > 1) {
				int x = c/w;
				total += x*(r-1);
			}
			
			String solution = "Case #" + task + ": " + total;
			System.out.println(solution);
			out.println(solution);
		}
		
		out.close();
		sc.close();
	}
}
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
			int amount = sc.nextInt();
			int[] counts = new int[amount];
			int sum = 0;
			for (int i = 0; i < amount; i++) {
				counts[i] = sc.nextInt();
				sum += counts[i];
			}
			String sol = "";
			if (sum%2 == 1) {
				int max1 = 0;
				for (int i = 0; i < amount; i++) {
					if (counts[i] > counts[max1]) {
						max1 = i;
					}
				}
				counts[max1]--;
				char first = (char)(max1+'A');
				sol += first;
				sum--;
			}
			while(sum > 0) {
				int max1 = 0;
				for (int i = 0; i < amount; i++) {
					if (counts[i] > counts[max1]) {
						max1 = i;
					}
				}
				counts[max1]--;
				int max2 = 0;
				for (int i = 0; i < amount; i++) {
					if (counts[i] > counts[max2]) {
						max2 = i;
					}
				}
				counts[max2]--;
				char first = (char)(max1+'A');
				char second = (char)(max2+'A');
				if (sol.length() > 0) {
					sol += " ";
				}
				sol += first;
				sol += second;
				sum -= 2;
			}
			
			String solution = "Case #" + task + ": " + sol;
			System.out.println(solution);
			out.println(solution);
		}
		
		out.close();
		sc.close();
	}
}
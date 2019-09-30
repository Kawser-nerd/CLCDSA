import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
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
			int k = sc.nextInt();
			int l = sc.nextInt();
			int s = sc.nextInt();
			
			String keys = sc.next();
			String target = sc.next();
			
			HashMap<Character, Double> freq = new HashMap<Character, Double>();
			for (char c = 'A'; c <= 'Z'; c++) {
				freq.put(c, 0.0);
			}
			
			for (int i = 0; i < keys.length(); i++) {
				char c = keys.charAt(i);
				freq.put(c, freq.get(c)+1);
			}
			
			for (char c = 'A'; c <= 'Z'; c++) {
				freq.put(c, freq.get(c)/keys.length());
			}
			
			int overlap = 0;
			for (int i = 1; i < target.length(); i++) {
				if (target.charAt(i) == target.charAt(0)) {
					boolean poss = true;
					for (int j = i+1; j < target.length(); j++) {
						if (target.charAt(j) != target.charAt(j-i)) {
							poss = false;
							break;
						}
					}
					if (poss) {
						overlap = target.length()-i;
						break;
					}
				}
			}
			
			int maxBananas = 1 + (s-l)/(target.length()-overlap);
			
			double possibility = 1;
			for (int i = 0; i < target.length(); i++) {
				char c = target.charAt(i);
				possibility *= freq.get(c);
			}
			
			if (possibility == 0) maxBananas = 0;
			
			double toGive = (possibility*((double)s-(double)l+1));
			double toKeep = ((double)maxBananas) - toGive;
			
			String solution = "Case #" + task + ": " + toKeep;
			System.out.println(solution);
			out.println(solution);
		}
		
		out.close();
		sc.close();
	}
}
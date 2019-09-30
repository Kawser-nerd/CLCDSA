import java.util.Scanner;

public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; i++) {
			System.out.printf("Case #%d: %s\n", i + 1, exec());
		}
	}
	
	public static String exec() {
		int n = sc.nextInt();
		int[] s1 = new int[n];
		int[] s2 = new int[n];
		for (int i = 0; i < n; i++) {
			s1[i] = sc.nextInt();
			s2[i] = sc.nextInt();
		}
		
		int stars = 0;
		int goal = n * 2;
		int[] obtained = new int[n];
		int plays = 0;
		loop:
		while (stars < goal) {
			// First, grab 2 stars in any level that we can do that in.
			for (int i = 0; i < n; i++) {
				if (s2[i] > stars) continue;
				if (obtained[i] == 2) continue;
				stars += 2 - obtained[i];
				obtained[i] = 2;
				plays++;
				continue loop;
			}
			
			// Next, grab 1 star in whatever level we can do that in, and the 2-star goal is the furthest away.
			int s2OfWinner = -1;
			int idxOfWinner = -1;
			for (int i = 0; i < n; i++) {
				if (obtained[i] != 0) continue;
				if (s1[i] > stars) continue;
				if (s2[i] < s2OfWinner) continue;
				s2OfWinner = s2[i];
				idxOfWinner = i;
			}
			if (s2OfWinner == -1) return "Too Bad";
			stars++;
			obtained[idxOfWinner] = 1;
			plays++;
		}
		
		return String.valueOf(plays);
	}
}

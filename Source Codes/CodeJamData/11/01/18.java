import java.util.Scanner;


public class A {
	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %d\n", i + 1, exec());
	}
	
	private static int exec() {
		int n = sc.nextInt();
		boolean[] ri = new boolean[n];
		int[] bi = new int[n];
		for (int i = 0; i < n; i++) {
			ri[i] = sc.next().equalsIgnoreCase("O");
			bi[i] = sc.nextInt();
		}
		return calc(ri, bi);
	}
	
	private static int calc(boolean[] ri, int[] bi) {
		int[] pos = {1, 1};
		
		int instr = 0;
		int time = 0;
		
		while (true) {
			if (instr >= ri.length) break;
			time++;
			
			// Move robots to nearest location.
			int nextLocationA = -1, nextLocationB = -1;
			for (int i = instr; i < ri.length; i++) {
				if (ri[i]) {
					nextLocationA = bi[i];
					break;
				}
			}
			for (int i = instr; i < ri.length; i++) {
				if (!ri[i]) {
					nextLocationB = bi[i];
					break;
				}
			}
			
			if (nextLocationA > -1 && pos[0] != nextLocationA) {
				if (pos[0] < nextLocationA) pos[0]++;
				else pos[0]--;
			} else {
				nextLocationA = -1; //Don't move.
			}
			
			if (nextLocationB > -1 && pos[1] != nextLocationB) {
				if (pos[1] < nextLocationB) pos[1]++;
				else pos[1]--;
			} else {
				nextLocationB = -1; //Don't move.
			}
			
			if (pos[ri[instr] ? 0 : 1] == bi[instr]) {
				//We're at the right position. Did we spend this turn moving?
				boolean pressIt = false;
				if (ri[instr] && nextLocationA == -1) pressIt = true;
				if (!ri[instr] && nextLocationB == -1) pressIt = true;
				if (pressIt) instr++;
			}
		}
		
		return time;
	}
}

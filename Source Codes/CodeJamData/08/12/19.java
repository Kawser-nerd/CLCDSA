import java.util.ArrayList;
import java.util.Scanner;

class Require {
	int index;
	boolean malted;
}
public class Milkshake {
	public static void main(String args[]) {
		int caseTotal;
		int caseNum = 1;
		int milkshake;
		int customer;
		int type;
		Scanner scanner = new Scanner(System.in);
		
		caseTotal = scanner.nextInt();
		while (caseTotal != 0) {
			System.out.print("Case #" + caseNum + ":");
			milkshake = scanner.nextInt();
			customer = scanner.nextInt();
			
			boolean results[] = new boolean[milkshake];
			for (int i=0; i<milkshake; i++) {
				results[i] = false;
			}
			
			ArrayList<Require> requires[] = new ArrayList[customer];
			for (int i=0; i<customer; i++) {
				requires[i] = new ArrayList<Require>();
				type = scanner.nextInt();
				for (int j=0; j<type; j++) {
					Require require = new Require();
					require.index = scanner.nextInt() - 1;
					if (scanner.nextInt() == 0) require.malted = false;
					else require.malted = true;
					requires[i].add(require);
					
					/*if (type == 1 && require.malted) {
						results[require.index] = true;
					}*/
				}
			}
			
			boolean changed = true;
			boolean allMeets = true;
			while (changed && allMeets) {
				changed = false;
				allMeets = true;
				for (int i=0; i<customer; i++) {
					boolean meets = false;
					for (Require require :  requires[i]) {
						if (results[require.index] == require.malted) {
							meets = true;
							break;
						}
					}
					if (!meets) {
						for (Require require :  requires[i]) {
							if (require.malted) {
								results[require.index] = true;
								meets = true;
								changed = true;
							}
						}
					}
					if (!meets) {
						allMeets = false;
						break;
					}
				}
			}
			if (allMeets) {
				for (int i=0; i<milkshake; i++) {
					if (results[i] == true) System.out.print(" 1");
					else System.out.print(" 0");
				}
				System.out.println();
			} else {
				System.out.println(" IMPOSSIBLE");
			}
			
			++caseNum;
			--caseTotal;
		}
	}
}

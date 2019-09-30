import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {
			int N = Integer.parseInt(sc.next());
			int Q = Integer.parseInt(sc.next());
			String S = sc.next();
			int[][] lr = new int[Q][2];
			for(int i = 0; i < Q; i ++) {
				lr[i][0] = Integer.parseInt(sc.next());
				lr[i][1] = Integer.parseInt(sc.next());
			}
			final String AC = "AC";
			int[][] counter = new int[S.length()][2];
			int count = 0;
			for(int i = 0; i < S.length()-1; i++) {
				counter[i][1] = count;
				if(AC.equals(S.substring(i, i +2))) {
					count++;
				}
			}
			
			counter[S.length()-1][1] = count;
			for(int i = 0; i < Q; i++) {
				System.out.println(counter[lr[i][1] -1][1] - counter[lr[i][0] -1][1]);
			}
		} // Scanner Close
	}
}
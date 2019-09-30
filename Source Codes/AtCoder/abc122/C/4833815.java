import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		String S  = sc.next();
		
		String S2 = S.replaceAll("AC","10");
		//System.out.println(S2);
		int [] AC = new int [N];
			//System.out.println(S2.charAt(0));
			//System.out.println(S2.charAt(0) == '1');
		if (S2.charAt(0) == '1')
			
			AC[0] = 1;
		for (int i = 1; i < N; i++) {
			if (S2.charAt(i) == '1')
				AC[i] = AC[i-1] + 1;
			else
				AC[i] = AC[i-1];
			//System.out.print(AC[i]);
		}
		int l;
		int r;

		for (int i = 0; i < Q; i++) {
			l = sc.nextInt();
			r = sc.nextInt();
			if (l == 1)
				System.out.println(AC[r-2]);
			else
				System.out.println(AC[r-2] - AC[l-2]);
		}
	}
}
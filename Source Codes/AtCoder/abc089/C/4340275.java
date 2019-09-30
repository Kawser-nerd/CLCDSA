import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		
		long M = 0L, A = 0L, R = 0L, C = 0L, H = 0L;
		for (int i=0; i<n; i++) {
			String s = sc.next();
			if (s.charAt(0) == 'M') M++;
			else if (s.charAt(0) == 'A') A++;
			else if (s.charAt(0) == 'R') R++;
			else if (s.charAt(0) == 'C') C++;
			else if (s.charAt(0) == 'H') H++;
		}
		
		long ans = 0L;
		ans += R * C * H;
		ans += A * C * H;
		ans += A * R * H;
		ans += A * R * C;
		
		ans += M * C * H;
		ans += M * R * H;
		ans += M * R * C;
		
		ans += M * A * H;
		ans += M * A * C;
		
		ans += M * A * R;
		
		System.out.println(ans);
		
	}
}
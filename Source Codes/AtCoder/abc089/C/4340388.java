import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		long[] ar = new long[5];
		for (int i=0; i<n; i++) {
			String s = sc.next();
			if (s.charAt(0) == 'M') ar[0]++;
			else if (s.charAt(0) == 'A') ar[1]++;
			else if (s.charAt(0) == 'R') ar[2]++;
			else if (s.charAt(0) == 'C') ar[3]++;
			else if (s.charAt(0) == 'H') ar[4]++;
		}
		
		long ans = 0L;
		for (int i=0; i<Math.pow(2,5); i++) {
			String s = String.valueOf(Integer.toBinaryString(i));
			int bitNum = 0;
			for (int j=0; j<s.length(); j++) {
				if (s.charAt(j) == '1') bitNum++;
			}
			if (bitNum != 3) continue;
			
			long temp = 1L;
			for (int j=0; j<5; j++) {
				if ((1&i>>j) == 1) {
					temp *= ar[j];
				}
			}
			ans += temp;
			
		}
		
		System.out.println(ans);
		
	}
}
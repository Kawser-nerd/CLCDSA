import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int digits = 0;
		int MSB = N;
		while (MSB > 0) {
			digits++;
			MSB /= 10;
		}
		
		int total = 0;
		while (digits >= 3) {
			total += sgs(digits, N, 0);
			digits--;
		}
		
		System.out.println(total);
	}
	
	static int sgs(int digit, int N, int value) {
		if (digit == 0) {
			if (isValid(value, N)) {
				//System.out.println(value);
				return 1;
			}
			return 0;
		}
		int n1 = sgs(digit-1, N, value*10 + 3);
		int n2 = sgs(digit-1, N, value*10 + 5);
		int n3 = sgs(digit-1, N, value*10 + 7);
		return n1+n2+n3;
	}
	
	static boolean isValid(int value, int N) {
		if (value <= N) {
			int threeCount = 0;
			int fiveCount = 0;
			int sevenCount = 0;
			while (value > 0) {
				switch(value%10) {
					case 3:
						threeCount++;
						break;
					case 5:
						fiveCount++;
						break;
					case 7:
						sevenCount++;
						break;
					default:
						break;
				}
				value /= 10;
			}
			if (threeCount > 0 && fiveCount > 0 && sevenCount > 0) {
				return true;
			}
		}
		return false;
	}

}
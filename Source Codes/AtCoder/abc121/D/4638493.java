import java.util.*;

public class Main {
	
	public static class MyPair implements Comparable<MyPair> {
		int cost;
		int supply;
		
		public MyPair(int cost, int supply) {
			this.cost = cost;
			this.supply = supply;
		}
		
		@Override
		public int compareTo(MyPair other) {
			return (this.cost - other.cost);
		}
	}
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		boolean AOdd = A%2 == 1;
		boolean BOdd = B%2 == 1;
		
		if (A == B) {
			System.out.println(A);
		} else if (AOdd && BOdd) {
			long diff = B - A;
			long LSB = (diff)/2%2;
			if (LSB == 1) {
				System.out.println(A-1);
			} else {
				System.out.println(A);
			}
		} else if (AOdd && !BOdd) {
			long diff = B - A;
			long LSB = (diff)/2%2;
			long BToCompare = B + LSB;
			long AToCompare = A;
			long solution = 0;
			long multiplier = 1;
			while (BToCompare > 0) {
				if (AToCompare == 0) {
					solution += BToCompare%2*multiplier;
					BToCompare /= 2;
				} else {
					if (BToCompare%2 != AToCompare%2) {
						solution += multiplier;
					}
					BToCompare /= 2;
					AToCompare /= 2;
				}
				multiplier *= 2;
			}
			System.out.println(solution);
		} else if (!AOdd && BOdd) {
			long diff = B - A;
			long LSB = (diff+1)/2%2;
			System.out.println(LSB);
		} else {
			long diff = B - A;
			long LSB = (diff)/2%2;
			System.out.println(B+LSB);
		}
    }
  
}
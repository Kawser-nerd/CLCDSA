import java.util.*;

public class Main {
	
	static class Burger {
		
		public static long getNumPatties(int level) {
			return pow(2, level+1)-1;
		}
		
		public static long getHeight(int level) {
			return pow(2, level+2)-3;
		}
		
		static long pow(int a, int b) {
			long product = 1;
			while (b > 0) {
				product *= a;
				b--;
			}
			return product;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long X = sc.nextLong();
		
		System.out.println(countPatties(N, X));
		
	}
	
	public static long countPatties(int level, long x) {
		if (x == 0) {
			return 0;
		} else if (level == 0) {
			return 1;
		} else if (x >= Burger.getHeight(level) - level) {
			return Burger.getNumPatties(level);
		}
		
		if (x < Burger.getHeight(level-1)+2) {
			return countPatties(level-1, x-1);
		} else {
			return Burger.getNumPatties(level-1)+1+countPatties(level-1, x-Burger.getHeight(level-1)-2);
		}
	}

}
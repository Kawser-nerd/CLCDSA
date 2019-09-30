import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n == 1) {
			System.out.println("Not Prime");
			return;
		}
		if(isPrime(n)) {
			System.out.println("Prime");
		} else {
			if(isFakePrime(n)) {
				System.out.println("Prime");
			} else {
				System.out.println("Not Prime");
			}
		}
	}

	public static boolean isPrime(int n) {
		for(int i = 2 ; i * i <= n ; i++) {
			if(n == i) continue;
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static boolean isFakePrime(int n) {
		if(n % 10 % 2 != 0 && (n % 10) != 5) {
			int sum = 0;
			while(n > 0) {
				sum += n % 10;
				n /= 10;
			}
			if(sum % 3 != 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

}
import java.util.*;

public class Main {
	
	static int[] divisors;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		ArrayList<Integer> primeNumbersArray = getPrimes(N);
		int[][] primeNumbers = new int[primeNumbersArray.size()][N+1];
		
		for (int i = 0; i < primeNumbers.length; i++) {
			primeNumbers[i] = occurrences(primeNumbersArray.get(i), N);
		}
		
		
		
		int two = 0;
		int four = 0;
		int fourteen = 0;
		int twentyfour = 0;
		int seventyfour = 0;
		
		for (int i = 0; i < primeNumbers.length; i++) {
			if (primeNumbers[i][N] >= 2) {
				two++;
			}
			if (primeNumbers[i][N] >= 4) {
				four++;
			}
			if (primeNumbers[i][N] >= 14) {
				fourteen++;
			}
			if (primeNumbers[i][N] >= 24) {
				twentyfour++;
			}
			if (primeNumbers[i][N] >= 74) {
				seventyfour++;
			}
		}
		/*
		System.out.println(two+" "+four+" "+fourteen+" "+twentyfour+" "+seventyfour);
		for (int i = 0; i < primeNumbers.length; i++) {
			for (int j = 0; j < primeNumbers[0].length; j++) {
				System.out.print(primeNumbers[i][j] + " ");
			}
			System.out.println();
		}
		*/
		int t1 = twentyfour * (two-1);
		int t2 = nCr(four, 2) * (two-2);
		int t3 = seventyfour;
		int t4 = fourteen * (four-1);
		System.out.println(t1+t2+t3+t4);
	}
	
	static int nCr(int n, int r) {
		if (r > n) {
			return 0;
		}
		return factorial(n, r)/factorial(n-r, 1);
	}
	
	static int factorial(int n, int m) {
		int product = 1;
		while (n > m) {
			product *= n;
			n--;
		}
		return product;
	}
	
	static int[] occurrences(int prime, int N) {
		int[] occurrence = new int[N+1];
		occurrence[0] = prime;
		for (int i = 2; i <= N; i++) {
			int power = 0;
			int temp = i;
			while (temp > 0 && temp%prime == 0) {
				power++;
				temp /= prime;
			}
			occurrence[i] += occurrence[i-1] + power;
		}
		return occurrence;
	}
	
	static ArrayList<Integer> getPrimes(int N) {
		ArrayList<Integer> primeNumbers = new ArrayList<Integer>();
		
		for (int i = 2; i <= N; i++) {
			boolean isPrime = true;
			for (int j = 2; j <= Math.sqrt(i); j++) {
				if (i%j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primeNumbers.add(i);
			}
		}
		
		return primeNumbers;
	}
}
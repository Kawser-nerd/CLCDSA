import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_b.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-B.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		ArrayList<Integer> primes = primeSieve(1001);
		
		for (int test = 0; test < tests; test++) {
			int A = scan.nextInt();
			int B = scan.nextInt();
			int P = scan.nextInt();
			int[][] adjList = new int[B-A+1][];
			for ( int i = A; i <= B; i++) {
				ArrayList<int[]> factors = factorization(i, primes);
				ArrayList<Integer> tmp = new ArrayList<Integer>();
				for ( int[] a: factors) {
					if ( a[0] < P ) continue;
					tmp.add(a[0]);
				}
				adjList[i-A] = new int[tmp.size()];
				int index = 0;
				for ( int a: tmp) adjList[i-A][index++] = a;
			}
			boolean[] done = new boolean[B-A+1];
			Arrays.fill(done,false);
			int[] queue = new int[B-A+10];
			int first = 0; 
			int last = 0;
			int count = 0;
			int x;
			for ( int i = 0; i <= B-A; i++) {
				if ( done[i]) continue;
				first = 0; last = 0;
				count++;
				done[i] = true;
				queue[last++] = i;
				while ( first < last ) {
					x = queue[first++];
					for ( int dif: adjList[x]) {
						if ( x - dif >= 0 && !done[x-dif]) { queue[last++] = x-dif; done[x-dif] = true; }
						if ( x + dif <= B-A && !done[x+dif] ) { queue[last++] = x+dif; done[x+dif] = true; }
					}
				}
			}
			String answer = String.format("Case #%d: %d\n", test + 1, count);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
	
	class Node {
		int[] dif;
		int value;
		public Node(int value, ArrayList<int[]> factors, int P) {
			this.value = value;
		}
	}
	
	ArrayList<int[]> factorization( int x, ArrayList<Integer> primes) {
		ArrayList<int[]> answer = new ArrayList<int[]>();
		for ( int p: primes) {
			if ( p*p > x) break;
			if ( x % p == 0 ) {
				int m = 0;
				while ( x % p == 0 ) { x /= p; m++; }
				answer.add(new int[] { p, m});
			}
		}
		if ( x > 1 ) answer.add( new int[] { x, 1});
		return answer;
	}
	
	ArrayList<Integer> primeSieve(int n) {
		boolean[] isPrime = new boolean[n+1];
		ArrayList<Integer> answer = new ArrayList<Integer>();
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for ( int k = 2; k <= n; k++ ) {
			if ( !isPrime[k]) continue;
			answer.add(k);
			for ( int m = k; m <=n; m += k) isPrime[m] = false;
		}
		return answer;
	}
}

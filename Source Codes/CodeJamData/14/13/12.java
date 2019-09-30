package round1a;

import java.util.Random;
import java.util.Scanner;

public class C {
	public static void main(String[] args) {
//	print(1000,1000);
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt(), tot = 0;
			for (int i = 0; i<N;i++) {
				int tmp = sc.nextInt();
				if ((i > 0 && i+1 < N) && (tmp < i+1 || tmp > i+N/2)) tot++; 
			}
			System.out.println("Case #" + caze + ": " + (tot >= 610 ? "GOOD" : "BAD"));
		}
	}
	
	private static void print(int N, int cant) {
		System.out.println(cant);
		Random r = new Random(7);
		for (int i=0;i<cant;i++) {
			int[] val;
			boolean good;
			if (good = r.nextBoolean()) {
				val = genGood(N, r);
			} else {
				val = genBad(N, r);
			}
			System.out.println(N);
			for (int j = 0; j < val.length; j++) {
				System.out.print(val[j] + " ");
			}
			System.out.println(good);
		}
	}
	
	private static int[] genGood(int N, Random r) {
		int[] ret = get(N);
		for (int i = 0; i < N; i++) {
			int pos = i + r.nextInt(ret.length - i);
			int tmp = ret[i];
			ret[i] = ret[pos];
			ret[pos] = tmp;
		}
		return ret;
	}
	
	private static int[] genBad(int N, Random r) {
		int[] ret = get(N);
		for (int i = 0; i < N; i++) {
			int pos = r.nextInt(ret.length);
			int tmp = ret[i];
			ret[i] = ret[pos];
			ret[pos] = tmp;
		}
		return ret;
	}
	
	private static int[] get(int N) {
		int[] ret = new int[N];
		for (int i = 0; i < N; i++) {
			ret[i] = i;
		}
		return ret;
	}
}

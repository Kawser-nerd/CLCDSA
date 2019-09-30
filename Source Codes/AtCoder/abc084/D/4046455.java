import java.util.Scanner;

public class Main {
	static int MAX = 100001;
	static boolean[] isPrime = new boolean[MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		int[] l = new int[Q];
		int[] r = new int[Q];
		for(int i = 0; i < Q; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}
		sc.close();
		aryPrime();
		int[] c = new int[MAX];
		for(int i = 3; i < 100000; i++) {
			if(isPrime[i]) {
				if(isPrime[(i + 1) / 2]) {
					c[i] = c[i - 1] + 1;
				}else {
					c[i] = c[i - 1];
				}
			}else {
				c[i] = c[i - 1];
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < Q; i++) {
			int cnt = c[r[i]] - c[l[i] - 1];
			sb.append(cnt).append("\n");
		}
		System.out.print(sb.toString());
//		for(int i = 0; i < 15; i++) {
//			System.out.println(i + " " + c[i]);
//		}
//		for(int p = 3; p < 10; p++) {
//			if(isPrime[p]) {
//				System.out.println(p);
//			}
//		}
	}
	static void aryPrime(){
        int l = isPrime.length;
        for(int i = 0; i < l; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;
        int max = (int)Math.sqrt(l);
        for(int i = 2; i <= max; i++) {
            if(isPrime[i]) {
                for(int j = i * 2; j < l; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}
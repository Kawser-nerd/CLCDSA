import java.util.Scanner;
public class Main {
	static int MAX_DIGIT = 60;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long k = Long.parseLong(sc.next());
		long[] A = new long [n];

		for(int i=0;i<n;i++) {
			A[i] = Long.parseLong(sc.next());
		}
		sc.close();
		long res = 0;
		for(int d = MAX_DIGIT; d >= -1; --d) { // d = -1 ? X = k ???
	        if (d != -1 && !((k & 1L<<d)!=0)) continue;

	        long tmp = 0;
	        for (int e = MAX_DIGIT; e >= 0; --e) {
	            long mask = 1L<<e;
	            int num = 0;
	            for (int i = 0; i < n; ++i) if ((A[i] & mask)!=0) ++num;

	            if (e > d) {
	                if ((k & mask)!=0) tmp += mask * (n - num);
	                else tmp += mask * num;
	            }
	            else if (e == d) {
	                tmp += mask * num;
	            }
	            else {
	                tmp += mask * Math.max(num, n - num);
	            }
	        }
	        res = Math.max(res, tmp);
	    }
	    System.out.println(res);
	}
}
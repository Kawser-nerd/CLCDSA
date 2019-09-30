import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        long[] A = new long[N];
        long[] B = new long[N];
        for (int i = 0; i < N; i++) {
        	A[i] = sc.nextLong();
        	B[i] = sc.nextLong();
        }
        
        long[] map = new long[N];
    	map[N-1] =  A[N-1] % B[N-1] == 0 ? 0 : B[N-1] - (A[N-1]  % B[N-1]);
        for (int i = N-2; 0 <= i; i--) {
        	long a = A[i];
        	long b = B[i];
        	map[i] = (A[i] + map[i+1]) % B[i] == 0 ? map[i+1] : (B[i] - (A[i] + map[i+1]) % B[i]) + map[i+1];
        }
        
        System.out.println(map[0]);
    }
}
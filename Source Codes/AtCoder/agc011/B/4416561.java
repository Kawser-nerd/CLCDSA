import java.util.Arrays;
import java.util.Scanner;

public class Main {
		public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] A = new long[n];
        for(int i=0;i<n;i++) A[i]=sc.nextLong();
        Arrays.sort(A);
        sc.close();
        long[] sum = new long[n];
        sum[0]=A[0];
        for(int i=1;i<n;i++) sum[i]=sum[i-1]+A[i];
        int res = 1;
        for(int i=n-1;i>=1;i--){
            if(A[i]<=2*sum[i-1]) res++;
            else break;
        }        
        System.out.println(res);
	}
}
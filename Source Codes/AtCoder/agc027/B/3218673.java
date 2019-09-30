import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long e = sc.nextLong();
        long[] x = new long[n];
        long[] xsum = new long[n+1];
        for(int i=0; i<n; i++){
            x[i] = sc.nextLong();
            xsum[i+1] = xsum[i] + x[i];
        } 
        sc.close();

        BigInteger ans = BigInteger.valueOf(Long.MAX_VALUE);

        for(int i=1; i<=n; i++){
            BigInteger mans = BigInteger.ZERO;
            int pos = 0;
            int count = 0;
            while(pos < n){
                int mcount = count==0 ? 1 : count;
                if(n - pos >= i){
                    long mval = (xsum[n-pos] - xsum[n-pos-i]) * (2*mcount+3);
                    mans = mans.add(BigInteger.valueOf(mval));
                    count++;
                    pos += i;
                }else{
                    long mval = xsum[n-pos] * (2*mcount+3);
                    mans = mans.add(BigInteger.valueOf(mval));
                    pos = n;
                }
            }
            mans = mans.add(BigInteger.valueOf((n+i)*e));
            ans = ans.min(mans);
        }

        System.out.println(ans.toString());

        
    }
}
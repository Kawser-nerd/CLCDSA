import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int k = sc.nextInt();
        sc.close();

        if(k == 0){
            System.out.println(n*n);
            return;
        }

        long ans = (n-k+1)*(n-k)/2;

        for(int i=k+1; i<n; i++){
            long tmp = ((n-i)/i)*(i-k);
            if(n%i >= k){
                tmp += n%i-k+1;
            }
            ans += tmp;
        }
        System.out.println(ans);
    }
}
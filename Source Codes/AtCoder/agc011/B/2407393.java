import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long[] sum = new long[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextLong();
        }
        sc.close();

        Arrays.sort(a);

        sum[0] = a[0];
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + a[i];
        }

        int pos = -1;
        for(int i=0; i<n-1; i++){
            if(sum[i] * 2 < a[i+1]){
                pos = i;
            }
        }


        System.out.println(n - (pos+1));


    }
}
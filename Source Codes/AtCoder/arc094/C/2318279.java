import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] a = new long[n][2];
        long sum = 0;
        for(int i=0; i<n; i++){
            a[i][0] = sc.nextLong();
            a[i][1] = sc.nextLong();
            sum += a[i][0];
        }

        long min = 1000000000000L;
        

        for(int i=0; i<n; i++){
            if(a[i][0] > a[i][1] && a[i][1] < min){
                min = a[i][1];
            }
        }

        if(min > 10000000000L){
            System.out.println(0);
            return;
        }

        System.out.println(sum - min);
    }
}
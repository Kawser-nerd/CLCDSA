import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
            sum += a[i];
        }

        long total = (long)n * (long)(n+1) / 2L;
        if(sum % total != 0){
            System.out.println("NO");
            return;
        }

        if(n == 1){
            System.out.println("YES");
            return;
        }

        int [] d = new int[n];
        int num = (int)(sum / total);

        d[0] = a[0] - a[n-1] - num;
        for(int i=1; i<n; i++){
            d[i] = a[i] - a[i-1] - num;
        }

        int sum2 = 0;
        for(int i=0; i<n; i++){
            if(d[i] % (n) != 0 || d[i] > 0){
                System.out.println("NO");
                return;
            }
            sum2 += d[i] / n;
        }

        if(sum2 + num == 0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }

}
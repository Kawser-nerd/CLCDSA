import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        long a[][] = new long[n][2];
        for(int i = 0;i<n;i++){
            a[i][0] = sc.nextLong();
            a[i][1] = sc.nextLong();
            sc.nextLine();
        }
        Arrays.sort(a,(x,y) -> Long.compare(x[0],y[0]));
        long ans = 0;
        for(int i = 0;i<n;i++){
            if(m == 0){
                break;
            }else if(a[i][1] > m){
                ans += m * a[i][0];
                m = 0;
            }else{
                ans += a[i][0] * a[i][1];
                m -= a[i][1];
            }
        }

        System.out.println(ans);
    }
}
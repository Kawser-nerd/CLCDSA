import java.util.*;

public class Main {
    private static int n;
    private static int k;
    private static int a[];

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        k = scan.nextInt();
        a = new int[n];

        for (int i=0;i<n;i++) a[i] = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        boolean b[] = new boolean[n-1];
        int count = 0;
        int ans = 0;
        for (int i=0;i<n-1;i++){
            if(a[i] < a[i+1]) b[i] = true;
            else b[i] = false;

            if (b[i]){
                count++;
                if (count >= k-1) ans++;
            }else count = 0;
        }

        if(k == 1) System.out.println(n);
        else System.out.println(ans);
    }
}
import java.util.Scanner;

/**
 * Created by mizuk on 2017/07/26.
 */
public class Main {

    private static long x = 0;   //????
    private static long y = 0;   //????
    private static int N;
    private static int a[];
    private static long ans;

    public static void input(){
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        a = new int[N];

        for(int i=0;i<N;i++) {
            a[i] = scan.nextInt();
        }
    }

    public static void main(String args[]){
        //??
        input();

        //x,y???
        x = a[0];
        for(int i=1;i<N;i++){
            y += a[i];
        }

        ans = Math.abs(x-y);
        for(int i=1;i<N-1;i++){
            x += a[i];
            y -= a[i];
            ans = Math.min(Math.abs(x-y) , ans);
        }
        System.out.println(ans);
    }
}
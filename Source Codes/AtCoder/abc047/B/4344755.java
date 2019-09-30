import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int W = sc.nextInt();
        int H = sc.nextInt();
        int N = sc.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        int[] a = new int[N];
        int x_min = 0;
        int x_max = W;
        int y_min = 0;
        int y_max = H;
        
        for(int i = 0; i < N; i++){
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            a[i] = sc.nextInt();
        }
        
        for(int i = 0; i < N; i++){
            if(a[i] == 1){
                if( x[i] > x_min )x_min = x[i];
            }
            if(a[i] == 2){
                if( x[i] < x_max )x_max = x[i];
            }
            if(a[i] == 3){
                if( y[i] > y_min )y_min = y[i];
            }
            if(a[i] == 4){
                if( y[i] < y_max )y_max = y[i];
            }
        }
        
        int ans;
        if((x_min < x_max) && (y_min < y_max)){
            ans = (x_min - x_max) * (y_min - y_max);
        }else{
            ans = 0;
        }
        
        System.out.println(ans);
    }
}
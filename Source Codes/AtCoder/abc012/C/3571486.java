import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
       int N = sc.nextInt();
       long ALL = 2025;
       long ans = ALL - N;
       for(int i = 1; i <= 9; i++){
           if(ans % i ==0&& ans / i <= 9){
               System.out.println(i +" x "+ans / i);
           }
       }
        
    }
}
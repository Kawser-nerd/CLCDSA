import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long Q=sc.nextLong();
        long H=sc.nextLong();
        long S=sc.nextLong();
        long D=sc.nextLong();
        long N=sc.nextLong();
        long L1=Math.min(S,Math.min(4*Q,2*H));
        if(2*L1<D){
            System.out.println(N*L1);
        }else{
            long x=N/2;
            
            System.out.println(D*x+L1*(N%2));
        }
    }
}
import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }
    void solve() {
        Scanner sc = new Scanner(System.in);
        long N=sc.nextLong();
        long H=sc.nextLong();
        long A=sc.nextLong();
        long B=sc.nextLong();
        long C=sc.nextLong();
        long D=sc.nextLong();
        long E=sc.nextLong();
        long ans=INF;
        if(H-N*E>0){
            System.out.println("0");
            return;
        }
        for(long x=0;x<=N;x++){
            double y=(double)((N-x)*E-H-B*x)/(D+E);
            long Y;
            if(y<0){
                Y=0;
            }else{
                Y=((N-x)*E-H-B*x)/(D+E)+1;
            }
            ans=Math.min(ans,x*A+C*Y);
        }
        System.out.println(ans);
    }
}
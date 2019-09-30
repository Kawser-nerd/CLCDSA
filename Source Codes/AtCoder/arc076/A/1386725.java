import java.util.*;


/**
 * Created by takaesumizuki on 2017/06/14.
 */
public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Long facN = this.calcfac(N);
        Long facM = this.calcfac(M);
        if( N == M ){
            System.out.println(2 * facN * facM % 1000000007);
        }else if(N + 1 == M || N == M + 1){
            System.out.println(facN * facM % 1000000007);
        }else{
            System.out.println(0);
        }

    }

    Long calcfac(int num){
        Long sum = new Long(1);
        for(int i = num ; i > 0; i--){
            sum *= i;
            sum %= 1000000007;
        }
        return sum;
    }

    public static void main(String[] args) {
        new Main().run();
    }


}
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        try{
            //??
            int N = scan.nextInt();
            int X = scan.nextInt();
            int[] x_ = new int[N];
            int[] d_ = new int[N];
            for(int i = 0; i < N; i++){
                x_[i] = scan.nextInt();
                d_[i] = Math.abs(X-x_[i]);
            }

            int D = gcd(d_, N);

            System.out.println(D);

        }finally{
            scan.close();
        }
    }

    static int gcd(int[] d, int n){
        int D = d[0];
        for(int i = 1; i < n; i++){
            while(d[i] % D != 0){
                int tmp = d[i] % D;
                d[i] = D;
                D = tmp;
            }
        }
        return D;
    }
}
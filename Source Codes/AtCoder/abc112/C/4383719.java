import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        try{
            //??
            int N = scan.nextInt();
            int[] x = new int[N];
            int[] y = new int[N];
            int[] h = new int[N];
            for(int i = 0; i < N; i++){
                x[i] = scan.nextInt();
                y[i] = scan.nextInt();
                h[i] = scan.nextInt();
            }

            int X = 0;
            int Y = 0;
            int H = 0;
            loop: for(int cx = 0; cx <= 100; cx++){
                for(int cy = 0; cy <= 100; cy++){
                    for(int i = 0; i < N; i++){
                        if(h[i] != 0){
                            H = h[i] + Math.abs(cx-x[i]) + Math.abs(cy-y[i]);
                            break;
                        }
                    }
                    H = getHeight(H, cx, cy, N, h, x, y);
                    if(H != -1){
                        X = cx;
                        Y = cy;
                        break loop;
                    }
                }
            }

            System.out.println(X+" "+Y+" "+H);

        }finally{
            scan.close();
        }
    }

    static int getHeight(int H, int cx, int cy, int N, int[] h, int[] x, int[] y){
        for(int i = 0; i < N; i++){
            if(h[i] != Math.max(H-Math.abs(cx-x[i])-Math.abs(cy-y[i]), 0)){
                H = -1;
            }
        }
        return H;
    }
}
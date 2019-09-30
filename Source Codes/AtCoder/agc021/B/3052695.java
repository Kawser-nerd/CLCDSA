import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] x = new int[n][2];
        for(int i=0; i<n; i++){
            x[i][0] = sc.nextInt();
            x[i][1] = sc.nextInt();
        }
        sc.close();

        if(n == 2){
            System.out.println(0.5);
            System.out.println(0.5);            
            return;
        }

        long[] num = new long[n];
        final int N = 3500000;
        double r = Math.pow(10, 11);

        for(int i=0; i<N; i++){
            double theta = 2.0d * Math.PI * (double)i / (double)N;
            double mx = r * Math.cos(theta);
            double my = r * Math.sin(theta);            
            double min = Math.pow(10, 200);
            int minpos = 0;
            for(int j=0; j<n; j++){
                double len = Math.pow((double)(x[j][0]) - mx, 2) + Math.pow((double)(x[j][1]) - my, 2);
                if(len < min){
                    min = len;
                    minpos = j;
                }
            }
            num[minpos]++;
        }

        for(int i=0; i<n; i++){
            System.out.println((double)(num[i]) / (double)N);
        }
    }
}
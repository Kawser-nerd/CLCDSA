import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();

        int[] x = new int[N];
        int[] y = new int[N];
        for(int i=0;i<N;++i){
            x[i]=scan.nextInt();
            y[i]=scan.nextInt();
        }

        for(int i=0;i<N;++i){
            List<Double> thetas = new ArrayList<>();
            for(int j=0;j<N;++j){
                if(i==j)continue;
                thetas.add(Math.atan2(y[j]-y[i], x[j]-x[i]));
            }
            thetas.sort(Comparator.naturalOrder());
            thetas.add(thetas.get(0)+2*Math.PI);
            double ans = 0;
            for(int k=0;k<N-1;++k)ans = Math.max(ans, thetas.get(k+1)-thetas.get(k)-Math.PI);

            System.out.println(ans/(Math.PI*2));
        }
    }
}
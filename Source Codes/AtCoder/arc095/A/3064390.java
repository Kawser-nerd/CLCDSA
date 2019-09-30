import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] xs = new int[n];
        for(int i=0; i<n; i++){
            x[i] = sc.nextInt();
            xs[i] = x[i];
        }
        Arrays.sort(xs);
        sc.close();

        int m1 = xs[n/2-1];
        int m2 = xs[n/2];

        for(int i=0; i<n; i++){
            if(x[i] <= m1){
                System.out.println(m2);
            }else{
                System.out.println(m1);
            }
        }

    }
}
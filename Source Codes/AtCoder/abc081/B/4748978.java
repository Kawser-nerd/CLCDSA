import java.util.*;
public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N;
        int[] L = new int[200];
        int dmin = 100;
        N = sc.nextInt();
        for (int i = 0; i < N; ++i) {
            int A;
            A = sc.nextInt();
            int d = 0;
            while (A % 2 == 0) {
                A /= 2;
                ++d;
            }
        	dmin = Math.min(dmin, d);
        }
        System.out.println(dmin);
    }
}
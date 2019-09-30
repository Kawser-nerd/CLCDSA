import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int i;

        int suuretsu[] = new int[n];

        if( n > 3) {
            suuretsu[0] = 0;
            suuretsu[1] = 0;
            suuretsu[2] = 1;
            for (i = 3; i < n; i++) {
                suuretsu[i] = (suuretsu[i - 3] + suuretsu[i - 2] + suuretsu[i - 1]) % 10007;
            }
            System.out.println(suuretsu[i-1]);
        }else if(n == 1 || n == 2)System.out.println(0);
        else if(n == 3) System.out.println(1);

    }
}
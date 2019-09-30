import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i = 0; i < N; i++) a[i] = sc.nextInt();

        int numberOfTwoDivisoraFactor = 0;
        for(int i = 0; i < N; i++){
            numberOfTwoDivisoraFactor += numberOfTwoDivisoraFactor(a[i]);
        }

        out.println(numberOfTwoDivisoraFactor);
    }

    public static int numberOfTwoDivisoraFactor(long num){
        if(num > 0 && num % 2 == 0){
            return 1 + numberOfTwoDivisoraFactor(num / 2);
        }
        return 0;
    }
}
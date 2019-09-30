import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Santa on 2016/10/16.
 */
public class Main {

    static int N;

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        N = scanner.nextInt();

        long total = 0;

        int[] map = new int[N + 5];

        int old = 0;
        int old2 = 0;

        for (int i = 0; i < N; i++) {
            int a = scanner.nextInt();
            total += Math.abs(a - old);


            if(i != 0) {

                if (Math.abs(a - old) + Math.abs(old - old2) == Math.abs(old2 - a)) {
                    map[i - 1] = 0;
                } else {
                    map[i - 1] = Math.abs(a - old) + Math.abs(old - old2) - Math.abs(old2 - a);
                }
            }

            old2 = old;
            old = a;
        }
        total += Math.abs(old);

        if (Math.abs(0 - old) + Math.abs(old - old2) == Math.abs(old2 - 0)) {
            map[N - 1] = 0;
        } else {
            map[N - 1] = Math.abs(0 - old) + Math.abs(old - old2) - Math.abs(old2 - 0);
        }

//        if(old2 * old < 0){
//            map[N - 1] = Math.abs(old) * 2;
//        }

//        System.out.println("total = " + total);
//        for (int i = 0; i < N; i++) {
//            System.out.println(map[i]);
//        }

        for (int i = 0; i < N; i++) {
            System.out.println(total - map[i]);
        }
    }




}
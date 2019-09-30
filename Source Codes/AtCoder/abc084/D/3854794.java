import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static boolean[] primes(int max){
        boolean[] p = new boolean[max+1];
        Arrays.fill(p,true);
        p[0]=false; p[1]=false;
        for(int i=2; i*i<=max; i++){
            if(p[i]){
                for(int j=2; i*j<=max; j++) p[i*j]=false;
            }
        }
        return p;
    }

    public static void main(String[] args) {

        int max = 100000;
        boolean[] prime = primes(max);
        boolean[] like2017 = new boolean[max+1];
        for(int i=1; i<=max; i+=2){
            like2017[i] = prime[i] && prime[(i+1)/2];
        }


        int[] count = new int[max+1];
        count[0]=0;
        for(int i=1; i<=max; i++){
            count[i] = count[i-1] + (like2017[i] ? 1 : 0);
        }


        Scanner sc = new Scanner(System.in);
        int Q = sc.nextInt();
        for(int q=0; q<Q; q++){
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(count[r] - count[l-1]);
        }


    }
}
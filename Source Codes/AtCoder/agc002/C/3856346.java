import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long L = sc.nextLong();
        long[] a = new long[N];
        for(int n=0; n<N; n++) a[n]=sc.nextLong();

        int root = -1;
        for(int n=1; n<N; n++){
            if(a[n] + a[n-1] >= L) root = n;
        }
        if(root<0){
            System.out.println("Impossible");
            return;
        }
        System.out.println("Possible");
        for(int i=1; i<root; i++) System.out.println(i);
        for(int i=N-1; i>root; i--) System.out.println(i);
        System.out.println(root);

    }
}
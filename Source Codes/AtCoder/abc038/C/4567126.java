import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i=0; i<N; i++) a[i] = sc.nextInt();
        System.out.println(func(N,a));
    }
    static long func(int N, int[] a){
        if(N == 1) return 1;
        int l = 0;
        int r = 1;
        long cnt = N;
        while(r<N){
            while(r<N && a[r]>a[r-1]) r++;
            long len = r-l;
            cnt += len*(len-1)/2;
            l = r;
            r++;
        }
        return cnt;
    }
}
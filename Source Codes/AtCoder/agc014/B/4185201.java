import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long[] bit0, bit1;
    static int n,m;
    // a[1]+...+a[i] = sum(bit1,i)*i+sum(bit0,i);
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt();
        bit0 = new long[n+5];
        bit1 = new long[n+5];
        for(int q=0;q<m;q++){
            int a = sc.nextInt(),b = sc.nextInt();
            if(b<a){
                int c=a;
                a=b;
                b=c;
            }
            addInterval(a,b-1,1);
        }
        boolean flag = true;
        for(int i=1;i<n;i++){
            long cur = overallSum(i)-overallSum(i-1);
            flag &= (cur%2==0);
        }
        String ans = flag?"YES":"NO";
        System.out.println(ans);
    }
    static long overallSum(int i){
        return ((long)i)*sum(bit1,i)+sum(bit0,i);
    }
    static void addInterval(int l, int r, long val){
        add(bit0,l,-val*(l-1));
        add(bit1,l,val);
        add(bit0,r+1,val*r);
        add(bit1,r+1,-val);
    }
    static void add(long[] bit, int idx, long val){
        while(idx<=n){
            bit[idx]+=val;
            idx += idx&(-idx);
        }
    }
    static long sum(long[] bit, int idx){
        long ans = 0;
        while(idx>0){
            ans += bit[idx];
            idx -= idx&(-idx);
        }
        return ans;
    }
}
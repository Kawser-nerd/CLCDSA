/*
import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] a = new long[n];
        int[][] bit = new int[n][40];
        int[] bitK=new int[40];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        for (int i = 0; i < n; i++) {
            int c=0;
            while (a[i]>0) {
                bit[i][c++]=(int)a[i]%2;
                a[i]/=2;
            }
        }
        int c=0;
        long t=k;
        while (t>0){
            bitK[c++]=(int)t%2;
            t/=2;
        }
        int[] cnt=new int[40];
        for (int i = 0; i < 40; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i]+=bit[j][i];
            }
        }
    }
}
*/
import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] f=new long[n+1];
        Point[] sushi = new Point[n];
        for (int i = 0; i < n; i++) {
            sushi[i]=(new Point(sc.nextInt(), sc.nextInt()));
        }
        HashSet<Integer> S=new HashSet<>();
        Arrays.sort(sushi,(p1, p2) -> p2.y - p1.y);
        long temp=0;
        int[] s=new int[n+1];
        for (int i = 0; i < k; i++) {
            temp += (long) sushi[i].y;
            S.add(sushi[i].x);
            s[sushi[i].x]++;
        }
        int size=S.size();
        f[size]=temp;
        int left=k-1,right=k;
        while (0<=left&&right<n){
            while (0<=left&&s[sushi[left].x]==1){
                left--;
            }
            while (right<n&&s[sushi[right].x]>0){
                right++;
            }
            if(0<=left&&right<n){
                f[size+1]=f[size]-sushi[left].y+sushi[right].y;
                size++;
                s[sushi[right].x]++;
                s[sushi[left].x]--;
                swap(sushi,left,right);
            }
        }
        long ans=0;
        for (long i = 1; i <= k; i++) {
            if(f[(int)i]>0)ans=max(ans,f[(int)i]+i*i);
        }
        out.println(ans);

    }
    static void swap(Point[] p,int a,int b){
        Point temp=p[a];
        p[a]=p[b];
        p[b]=temp;
    }
}
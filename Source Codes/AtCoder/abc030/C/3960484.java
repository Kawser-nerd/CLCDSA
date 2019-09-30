import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        for (int i = 0; i < m; i++) b[i] = sc.nextInt();
        solve(n,m,a,b,x,y);
    }
    static int t=0,ans=0,i=0,j=0;
    static void calc1(int n,int m,int[] a,int[] b,int x,int y){
        boolean f=true;
        while(i<n&&j<m){
            if(f){
                calc2(n,a,x,f);
                f=false;
            }else{
                calc2(m,b,y,f);
                f=true;
            }
        }
    }
    static void calc2(int n,int[] a,int x,boolean f){
        int k=f?i:j;
        if(t<=a[k]){
            t=a[k]+x;
            k++;
            ans++;
        }else{
            while (k<n&&a[k]<t)k++;
            if(k<n) {
                t = a[k] + x;
                ans++;
            }
        }
        if(f)i=k;
        else j=k;
    }
    static void solve(int n,int m,int[] a,int[] b,int x,int y){
        calc1(n,m,a,b,x,y);
        out.println(ans/2);
    }
}
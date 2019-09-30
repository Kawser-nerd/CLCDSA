import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int[] ng=new int[3];
        for (int i = 0; i < 3; i++) {
            ng[i]=sc.nextInt();
        }
        if(n<=3||!D(ng,n)){
            out.println(D(ng,n)?"YES":"NO");
            exit(0);
        }
        int[] cnt=new int[n+1];
        for (int i = 0; i <= n; i++) {
            cnt[i]=101;
        }
        if(D(ng,n))cnt[n]=0;
        for (int i = n-1; i > n-3; i--) {
            if(D(ng,i)){
                cnt[i]=1;
            }
        }
        for (int i = n-3; i >= 0; i--) {
            int min=101;
            if(D(ng,i)) {
                if (cnt[i + 1] <= 100) min = min(min, cnt[i + 1]);
                if (cnt[i + 2] <= 100) min = min(min, cnt[i + 2]);
                if (cnt[i + 3] <= 100) min = min(min, cnt[i + 3]);
            }
            cnt[i]=min+1;
        }
        if(cnt[0]<=100)out.println("YES");
        else out.println("NO");
    }
    static boolean D(int[] ng,int a){
        int c=0;
        for (int i = 0; i < ng.length; i++) {
            if(ng[i]==a)c++;
        }
        return c==0;
    }
}
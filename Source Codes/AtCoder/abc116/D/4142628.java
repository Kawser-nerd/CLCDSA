import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] f=new long[k+1];
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
              left--;
            }
        }
        long ans=0;
        for (long i = 1; i <= k; i++) {
            if(f[(int)i]>0)ans=max(ans,f[(int)i]+i*i);
        }
        out.println(ans);
    }
}
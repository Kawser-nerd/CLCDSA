/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
 */
import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long[] imos=new long[1000002];
        for (int i = 0; i < n; i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            imos[a]++;
            imos[b+1]--;
        }
        long ans=0;
        for (int i = 1; i < 1000002; i++) {
            imos[i]+=imos[i-1];
            ans=max(ans,imos[i]);
        }
        ans=max(imos[0],ans);
        out.println(ans);
    }
}
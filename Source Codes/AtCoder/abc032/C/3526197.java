import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
//Loop?????????????
//int????????????????
//Loop??????10?????????Loop?????
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long k=sc.nextLong();
        long[] s=new long[n];
        int ans=0;
        for (int i = 0; i < n; i++) {
            s[i]=sc.nextLong();
            if(s[i]==0){
                out.println(n);
                exit(0);
            }else if(s[i]<=k){
                ans=1;
            }
        }
        int r=0;
        long temp=1;
        for (int l = 0; l < n; l++) {
            while(r<n&&temp*s[r]<=k){
                temp*=s[r];
                ans=max(ans,r++-l+1);
            }
            if(r==l)r++;
            else temp/=s[l];
        }
        out.println(ans);
    }
}
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q  = sc.nextInt();
        long a, b;
        for(int i=0; i<q; i++){
            long tmpa = sc.nextLong();
            long tmpb = sc.nextLong();
            if(tmpa > tmpb){
                a = tmpb;
                b = tmpa;
            }else{
                a = tmpa;
                b = tmpb;
            }
            long ans = 0;
            ans += (a-1) * 2;

            int count = 0;
            long score = a*b;
            
            int l = 1;
            int r = 1000000000;
            while(r > l+1){
                int m = (l+r) / 2;
                if((long)m * (long)m < score){
                    l = m;
                }else{
                    r = m-1;
                }
            }
            if(l!= r && (long)(l+1) * (long)(l+1) < score) l++;

            if(l > a && l < b) ans += (l - a) * 2;
            if((long)l * (long)(l + 1) < score && l+1 != b) ans++;
            System.out.println(ans);
        }

    }
}
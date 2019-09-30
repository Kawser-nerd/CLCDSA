import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String S=sc.next();
        char[] s=S.toCharArray();
        long ans=INF;
        int c=0;
        for(int i=0;i<26;i++){
            int count=0;
            c=0;
            for(int j=0;j<S.length();j++){
                if(s[j]==(char)('a'+i)){
                    count=0;
                }else{
                    count++;
                }
                c=Math.max(count,c);
            }
            ans=Math.min(ans,c);
        }
        System.out.println(ans);
    }
}
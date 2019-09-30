import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int w=0,cnt=0;
        int n = sc.nextInt();
        int s = sc.nextInt();
        int t = sc.nextInt();
        for(int i=0;i<n;i++){
            w += sc.nextInt();
            if(s<=w && w<=t)
                cnt++;
        }
        System.out.println(cnt);
    }
}
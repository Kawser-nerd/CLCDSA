import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = Integer.MAX_VALUE;
        for(int i=1;i<=n/2;i++){
            ans = Math.min(ans,help(i)+help(n-i));
        }
        System.out.println(ans);
    }
    public static int help(int p){
        int ans = 0;
        while(p>0){
            ans += p%10;
            p /= 10;
        }
        return ans;
    }
}
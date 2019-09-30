import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] time = new int[n];
        for(int i=0;i<n;i++){
        	time[i] = sc.nextInt();
        }

        long now = 0;
        long ans = 0;
        for(int i=0;i<n;i++){
        	if(now>time[i]){
        		ans +=  t - (now - (long)time[i]);
        		now = t + time[i];
        	}
        	else{
        		ans += t;
        		now = t + time[i];
        	}
        }

        System.out.println(ans);
    }
}
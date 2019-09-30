import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
     	int n = sc.nextInt();   
     	int m = sc.nextInt();
     	long ans = 1;
     	long mod = (long)Math.pow(10, 9) + 7;
     	if(n==m){
     		for(int i=n;i>0;i--){
     			ans = ((ans * (long)i) % mod) * (long)i % mod;
     		}
     		ans = (ans * 2) % mod;
     	}
     	else if((int)Math.abs(n-m)==1){
     		for(int i=(int)Math.min(n, m);i>0;i--){
     			ans = ((ans * (long)i) % mod) * (long)i % mod;	
     		}
     		ans = (ans * (long)Math.max(n, m)) % mod;
     	}
     	else{
     		ans = 0;
     	}

     	System.out.println(ans);
    }
}
import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int[] a = new int[n];
        int ans = -1;
        for(int i=0;i<n;i++){
        	a[i] = sc.nextInt();
        }
        for(int i=0;i<n-1;i++){
        	if(a[i]+a[i+1]>=l){
        		ans = i+1;
        		break;
        	}
        }

        if(ans!=-1){
        	System.out.println("Possible");
        	for(int i=1;i<ans;i++){
        		System.out.println(i);
        	}
        	for(int i=n-1;i>=ans;i--){
        		System.out.println(i);
        	}
        }
        else{
        	System.out.println("Impossible");
        }
    }
}
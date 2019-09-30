import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
        	a[i] = sc.nextInt();
        }
        int x = 0;
        if((n-k)%(k-1)==0){
        	x = (n-k)/(k-1);
        }
        else{
        	x = (n-k)/(k-1) + 1;	
        }
        System.out.println(x+1);
    }
}
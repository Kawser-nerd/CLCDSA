import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String s = sc.next();
        int[] l = new int[q];
        int[] r = new int[q];
        for(int i=0;i<q;i++){
        	l[i] = sc.nextInt();
        	r[i] = sc.nextInt();
        }
        int[] len = new int[n];
        for(int i=1;i<n;i++){
        	if(s.charAt(i)=='C' && s.charAt(i-1)=='A'){
        		len[i] = len[i-1] + 1;
        	}
        	else{
        		len[i] = len[i-1];
        	}
        }

        for(int i=0;i<q;i++){
        	System.out.println(len[r[i]-1] - len[l[i]-1]);
        }
    }
}
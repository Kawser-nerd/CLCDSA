import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        String t = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<n;i++){
        	s[i] = sc.next();
        }
        int[][] num = new int[n][26];

        for(int i=0;i<n;i++){
        	for(int j=0;j<s[i].length();j++){
        		num[i][(int)s[i].charAt(j)-(int)'a']++;
        	}
        }

        int[] ans = new int[26];
        for(int i=0;i<26;i++){
        	ans[i] = num[0][i];
        	for(int j=1;j<n;j++){
        		ans[i] = Math.min(ans[i], num[j][i]); 
        	}
        }

        for(int i=0;i<26;i++){
        	for(int j=0;j<ans[i];j++){
        		System.out.print(t.charAt(i));
        	}
        }

        System.out.println();
    }
}
import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {
    public static int maxOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]>ans) ans=a[i];
    	}
    	return ans;
    }
    public static int minOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]<ans) ans=a[i];
    	}
    	return ans;
    }
    
    public static boolean unbalanced(String s){
        int[] count = new int[26];
        for(int i=0;i<s.length();i++){
        	count[s.charAt(i)-'a']++;
        }
        return maxOfArray(count)>s.length()/2;
    }
    public static String solve(String s){
        if(s.length()<3) return (unbalanced(s) ? "1 2" : "-1 -1");
        
        for(int i=0;i<s.length()-2;i++){
        	if(unbalanced(s.substring(i,i+3))) return ((i+1)+" "+(i+3));
        }
        return "-1 -1";
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(solve(s));
    }
}
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static String repeat(char c, int n){
        String ans = "";
        for(int i=0;i<n;i++) ans = ans + c;
        return ans;
    }
    public static int[] countChar(String s){
        int[] ans = new int[26];
        for(int i=0;i<s.length();i++){
        	ans[s.charAt(i)-'a']++;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] count = new int[26];
        for(int i=0;i<26;i++)count[i]=100;
        for(int n=0;n<N;n++){
        	String s = sc.next();
        	int[] a = countChar(s);
        	for(int i=0;i<26;i++) count[i]=Math.min(count[i],a[i]);
        }
        for(int i=0;i<26;i++){
        	char c = (char)('a'+i);
        	System.out.print(repeat(c,count[i]));
        }
        System.out.println();
    }
}
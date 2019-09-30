import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        PrintWriter out = new PrintWriter(System.out);
        out.println(help(s));
        out.flush();
    }
    static String help(String s){
        if(s.equals("zyxwvutsrqponmlkjihgfedcba")) return "-1";
        char[] a = s.toCharArray();
        int[] rec = new int[26];
        Arrays.fill(rec,-1);
        for(int i=0;i<a.length;i++) rec[a[i]-'a']=i;
        if(a.length<26){
            for(int i=0;i<26;i++){
                if(rec[i]==-1) return s+Character.toString((char)(i+'a'));
            }
            return "-1";
        }else{
            for(int start=24;start>=0;start--){
                if(a[start]=='z') continue;
                char cur = a[start];
                for(int i=cur-'a'+1;i<26;i++){
                    if(rec[i]>start){
                        return s.substring(0,start)+Character.toString((char)(i+'a'));
                    }
                }
            }
            return "-1";
        }
    }
}
import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char[] a = s.toCharArray();
        long n = (long) a.length;
        long[] rec = new long[26];
        for(char w:a) rec[w-'a']++;
        long ans = 1+n*(n-1)/2;
        for(int i=0;i<26;i++){
            ans -= rec[i]*(rec[i]-1)/2;
        }
        System.out.println(ans);
    }
}
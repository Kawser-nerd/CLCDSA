import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class B {

    Scanner scan;
    InputStream in;
    

    private int lineInt(){
        String s = scan.nextLine();
        return parseInt(s);
    }
    
    int nonZero(String s){
        int r =0;
        for(char c:s.toCharArray())if(c!='0')r++;
        return r;
    }
    
    boolean isMax(String s){
        for(int i=1;i<s.length();i++){
            if(s.charAt(i-1)<s.charAt(i))return false;
        }
        return true;
    }
    
    String next(String s){
        int b =-1;
        char[]c = s.substring(1).toCharArray();
        char f=s.charAt(0);
        for(int i=0;i<c.length;i++){
            if(c[i]>f){
                if(b==-1 || c[i]<c[b])b=i;
            }
        }
        char t = f;
        f = c[b];
        c[b]=t;
        sort(c);
        return f+new String(c);
    }
    
    String solve(){
        String s = scan.nextLine();
        if(nonZero(s)==1)return s+"0";
        if(isMax(s)){
            char[]c = s.toCharArray();
            int j =c.length-1;
            while(c[j]=='0')j--;
            char first = c[j];
            c[j]='0';
            sort(c);
            return first + new String(c);
        }
        for(int suff = 2;suff<=s.length();suff++){
            String x = s.substring(s.length()-suff);
            if(isMax(x))continue;
            String y = next(x);
            return s.substring(0,s.length()-suff)+y;
        }
        return "";
    }
    
    void solveAll(){
        int N = lineInt();
        for(int i=0;i<N;i++){
            String res = solve();
            System.out.printf("Case #%d: %s\n",i+1,res);
        }
    }
    
    B() throws Exception{
        in = new BufferedInputStream(new FileInputStream("B-large.in"));
        scan = new Scanner(in);
    }
    
    public static void main(String[] args) throws Exception{
        Locale.setDefault(Locale.US); 
        new B().solveAll();
    }

}

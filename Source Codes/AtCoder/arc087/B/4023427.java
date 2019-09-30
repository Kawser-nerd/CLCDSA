import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    int[][] rec = new int[1001][1001];
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int x = sc.nextInt(),y=sc.nextInt();
        int start=0,n=s.length;
        while(start<n&&s[start]=='F') start++;
        ArrayList<Integer> hori = new ArrayList<>(), vert = new ArrayList<>();
        int parity=0;
        int i=start;
        while(i<n){
            if(s[i]=='T'){
                parity = 1-parity;
                i++;
            }else{
                int j=i+1;
                while(j<n&&s[j]=='F') j++;
                if(parity==0) hori.add(j-i);
                else vert.add(j-i);
                i=j;
            }
        }
        String ans = help(x-start,hori)&&help(y,vert)?"Yes":"No";
        System.out.println(ans);
    }
    static boolean help(int target, ArrayList<Integer> step){
        int sum=0;
        for(int w:step) sum+=w;
        if(sum<Math.abs(target)) return false;
        if(sum==Math.abs(target)) return true;
        boolean[] cur = new boolean[2*sum+1], next = new boolean[2*sum+1];
        cur[sum]=true;
        for(int w:step){
            for(int j=0;j<=2*sum;j++){
                if(cur[j]){
                    next[j-w]=true;
                    next[j+w]=true;
                }
            }
            cur=next;
            next=new boolean[2*sum+1];
        }
        return cur[target+sum];
    }
}
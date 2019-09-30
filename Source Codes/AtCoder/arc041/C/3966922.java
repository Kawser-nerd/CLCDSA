import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long L = sc.nextLong();
        int[] x = new int[n];
        char[] dir = new char[n];
        for(int i=0;i<n;i++){
            x[i]=sc.nextInt();
            String d = sc.next();
            dir[i] = d.equals("L")?'L':'R';
        }
        long ans = help(n,x,dir,L);
        System.out.println(ans);
    }
    static long help(int n, int[] x, char[] dir, long len){
        long ans = 0;
        int start=0,end=n-1;
        while(start<n&&dir[start]=='L'){
            ans += x[start]-(start+1);
            start++;
        }
        while(end>=0&&dir[end]=='R'){
            ans += (len+1-(n-end))-x[end];
            end--;
        }
        // either end<start (all in one direction) or end>start
        // impossible that end==start
        LinkedList<Integer> curRight = new LinkedList<>();
        if(end<start) return ans;
        int left = x[start];
        while(start<=end){
            if(dir[start]=='R'){
                int right = start;
                while(right<end&&dir[right]=='R') curRight.add(x[right++]);
                int cntLeft = 0,leftStart=right;
                while(leftStart<=end&&dir[leftStart]=='L'){
                    leftStart++;
                    cntLeft++;
                }
                left = curRight.size()<=cntLeft?x[right-1]:x[right]-1;
                long res = -((long)curRight.size())*((long)curRight.size()-1)/2;
                while(curRight.size()>0) res+=left-curRight.poll();
                ans += res;
                start = right;
            }else{
                ans += x[start]-left-1;
                left++;
                start++;
            }
        }
        return ans;
    }
}
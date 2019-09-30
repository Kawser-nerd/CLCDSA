import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static int n;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] A = new int[n];
        for(int i=0;i<n;i++) A[i] = sc.nextInt();
        int ans = helper(A);
        System.out.println(ans);
    }
    static int helper(int[] a){
        HashSet<Integer> vis = new HashSet<>();
        int left = 0,right=0;
        int ans = 0;
        while(left<n){
            while(right<n&&!vis.contains(a[right])) vis.add(a[right++]);
            if(right==n){
                ans = Math.max(ans,right-left);
                return ans;
            }
            ans = Math.max(ans,right-left);
            while(left<n&&a[left]!=a[right]){
                vis.remove(a[left]);
                left++;
            }
            vis.remove(a[left++]);
        }
        return ans;
    }
}
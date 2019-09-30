import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long ans=0;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] sum = new long[n+1];
        for(int i=1;i<=n;i++) sum[i] = sum[i-1]+sc.nextLong()-k;
        long[] temp = new long[n+1];
        // mean >= k ==> sum >= 0 (every a[i]=a[i]-k)
        merge(0,n,sum,temp);
        PrintWriter out = new PrintWriter(System.out);
        out.println(ans);
        out.flush();
    }
    static void merge(int left, int right, long[] sum, long[] temp){
        if(left>=right) return;
        int mid = (left+right)/2;
        merge(left,mid,sum,temp);
        merge(mid+1,right,sum,temp);
        // suppose left part and right part are sorted respectively
        int start = mid+1;
        for(int i=left;i<=mid;i++){
            while(start<=right&&sum[start]-sum[i]<0) start++;
            ans += right+1-start;
        }
        int k=left,i=left,j=mid+1;
        while(i<=mid&&j<=right){
            if(sum[i]<sum[j]) temp[k++] = sum[i++];
            else temp[k++] = sum[j++];
        }
        while(i<=mid) temp[k++] = sum[i++];
        while(j<=right) temp[k++] = sum[j++];
        for(int m=left;m<=right;m++) sum[m] = temp[m];
    }
}
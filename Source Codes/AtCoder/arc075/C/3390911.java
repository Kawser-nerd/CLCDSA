import java.util.*;

class Main {
    static long[] sum;
    static int n;
    static long tot = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int K = sc.nextInt();
        sum = new long[n+1];
        for(int i=1;i<=n;i++) {
            sum[i] = sum[i-1]+sc.nextInt()-K;
        }
        // kind of like reverse number problem. Here we want to count how many (i,k) s.t. 0<=i<k<=n&&sum[i]<=sum[k];
        merge(0,n);
        System.out.println(tot);
    }
    static void merge(int left, int right){
        if(left>=right) return;
        int mid = (left+right)/2;
        merge(left,mid);
        merge(mid+1,right);
        int i=left,j=mid+1,k=0;
        long[] temp = new long[right-left+1];
        while(i<=mid&&j<=right){
            if(sum[i]<=sum[j]) {
                tot += mid-i+1;
                temp[k++] = sum[j++];
            }
            else temp[k++] = sum[i++];
        }
        while(i<=mid) temp[k++] = sum[i++];
        while(j<=right) temp[k++] = sum[j++];
        for(int m=0;m<temp.length;m++) sum[left+m] = temp[m];
    }
}
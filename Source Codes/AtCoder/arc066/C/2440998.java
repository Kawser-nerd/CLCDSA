import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long[] sum = new long[N];
        long[] a = new long[N];
        long[] abssum = new long[N+1];
        List<Integer> minusIndex = new ArrayList<>();
        for(int i=0;i<N;++i){
            if(i==0){
                a[i] = scan.nextLong();
                sum[i]=a[i];
            }else{
                boolean minus = (scan.next().equals("-"));
                a[i] = scan.nextLong();
                sum[i] = sum[i-1] + a[i]*(minus ? -1:1);
                if(minus)minusIndex.add(i-1);
            }
        }
        for(int i=N-1;i>=0;--i)abssum[i] = abssum[i+1]+a[i];

        long ans = sum[N-1];
        for(int i=0;i<minusIndex.size()-1;++i){
            ans = Math.max(ans, sum[minusIndex.get(i)] - abssum[minusIndex.get(i)+1] + 2*abssum[minusIndex.get(i+1)+1]);
        }
        System.out.println(ans);
    }
}
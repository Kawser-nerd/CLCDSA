import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        long ans = help(a,b);
        System.out.print(ans);
    }
    static long help(int[] a, int[] b){
        int len = b.length;
        boolean flag = true;
        for(int i=0;i<len;i++) flag &= (a[i]==b[i]);
        if(flag) return 0;
        long sum = 0;
        long min = Long.MAX_VALUE;
        for(int i=0;i<len;i++){
            sum += b[i];
            if(a[i]>b[i]) min = Math.min(min,b[i]);
        }
        return sum-min;
    }
}
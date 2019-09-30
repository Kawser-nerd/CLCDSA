import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];        
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            b[i] = sc.nextInt();
        }
        sc.close();

        long[] num = new long[29];
        long ans = 0;
        
        for(int i=0; i<29; i++){
            int[] ta = new int[n];
            int[] tb = new int[n];
            for(int j=0; j<n; j++){
                ta[j] = a[j] % (2 << i);
                tb[j] = b[j] % (2 << i);
            }
            Arrays.sort(tb);
            int pow1 = (2 << i) / 2;
            int pow2 = 2*pow1, pow3 = 3*pow1, pow4=4*pow1;
            for(int j=0; j<n; j++){
                int tmp1 = myBinarySearch(tb, pow1 - ta[j]);
                int tmp2 = myBinarySearch(tb, pow2 - ta[j]);
                int tmp3 = myBinarySearch(tb, pow3 - ta[j]);
                int tmp4 = myBinarySearch(tb, pow4 - ta[j]);                
                //if(tmp1 < 0) tmp1 = -tmp1 - 1;
                //if(tmp2 < 0) tmp2 = -tmp2 - 1;
                num[i] += tmp2 - tmp1 + tmp4 - tmp3;
            }

            if(num[i] % 2 == 1) ans += (2 << i) / 2;
        }

        System.out.println(ans);
    }
    
    public static int myBinarySearch(int[] la, int key){
        int l = -1;
        int r = la.length;
        while(r - l > 1){
            int m = (l + r) >> 1;
            if(la[m] >= key){
                r = m;
            }else{
                l = m;
            }
        }
        return r;
    }
}
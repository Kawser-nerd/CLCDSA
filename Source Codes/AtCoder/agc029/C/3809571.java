import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();

        boolean nodec = true;
        for(int i=1; i<n; i++){
            if(a[i] <= a[i-1]) nodec = false;
        }
        if(nodec){
            System.out.println(1);
            return;
        }

        
        int m = 500;
        int l = 1, r = 210000;
        int mid = 2;
        int[] dec = new int[m];

        out: while(r-l > 1){
            mid = (l+r)/2;
            dec = new int[m];
            Arrays.fill(dec, 1);
            nout: for(int i=1; i<n; i++){
                if(a[i] <= a[i-1] && a[i]-1 < m){
                    if(dec[a[i]-1] < mid){
                        dec[a[i]-1]++;
                    }else{
                        int pos = a[i]-1;
                        
                        while(pos > 0){
                            dec[pos-1]++;
                            for(int j=pos; j<m; j++){
                                dec[j] = 1;
                            }
                            if(dec[pos-1] <= mid) continue nout;
                            pos--;
                        }
                        l = mid;
                        continue out;
                    }
                }else{
                    for(int j=a[i]-1; j<m; j++){
                        dec[j] = 1;
                    }
                }
            }
            r = mid;
        }

        System.out.println(r);
    }
}
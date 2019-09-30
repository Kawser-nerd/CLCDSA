import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextLong();
        }
        sc.close();

        Arrays.sort(a);
        
        long ans = 0;
        long x = 0;
        for(int i=0; i<n-1; i++){
            int mi = n-i-1;
            if(a[mi] == a[mi-1]){
                if(x == 0){
                    x = a[mi];
                    i++;
                }else{
                    ans = x * a[mi];
                    break;
                }
            }
        }

        System.out.println(ans);
    }
}
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int min = n;
        int max = 0;
        for(int i = 0; i<n; i++){
            a[i] = sc.nextInt();
            if(a[i] < min) min = a[i];
            if(a[i] > max) max = a[i];
        }
        
        if(max - min >= 2){
            System.out.println("No");
            return;
        }

        if(min == max){
            if(min == 1 || min == n-1){
                System.out.println("Yes");
                return;
            }
            if(n / min >= 2){
                System.out.println("Yes");
                return;
            }
            System.out.println("No");
        }else{
            int nmin = 0;
            for(int ta: a){
                if(ta == min) nmin++;
            }
            int nmax = n - nmin;

            if(nmin < max && (max - nmin)*2 <= nmax){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }
        
    }
}
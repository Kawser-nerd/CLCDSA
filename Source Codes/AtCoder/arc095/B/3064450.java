import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int max = 0;
        int max2 = 0;
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
            if(a[i] > max){
                max2 = max;
                max = a[i];
            }else if(a[i] > max2){
                max2 = a[i];
            }
        }

        int half = 0, half2 = 0;
        int dif = Integer.MAX_VALUE, dif2 = Integer.MAX_VALUE;
        int mid = max / 2;

        for(int i=0; i<n; i++){
            int mdif = Math.abs(a[i] - mid);
            if(mdif < dif){
                half2 = half;
                half = a[i];
                dif2 = dif;
                dif = mdif;
            }else if(mdif < dif2){
                half2 = a[i];
                dif2 = mdif;
            }
        }

        if(max == half){
            System.out.println(max + " " + half2);
        }else{
            System.out.println(max + " " + half);
        }

    }
}
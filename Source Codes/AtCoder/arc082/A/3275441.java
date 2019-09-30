import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[100010];
        for(int i=0; i<n; i++){
            int atmp = sc.nextInt();
            a[atmp]++;
            a[atmp+1]++;
            a[atmp+2]++;
        }
        sc.close();

        int[] num = new int[n];
        int max = 0;
        for(int i=0; i<100010; i++){
            if(a[i] > max){
                max = a[i];
            }
        }

        System.out.println(max);
    }
}
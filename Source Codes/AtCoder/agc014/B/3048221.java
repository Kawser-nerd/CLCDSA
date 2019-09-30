import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int[] c = new int[100001];
        for(int i=0; i<m; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[a[i]]++;
            c[b[i]]++;
        }

        for(int i=0; i<c.length; i++){
            if(c[i] % 2 != 0){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");

    }
}
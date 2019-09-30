import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];
        boolean isAns = false;

        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.next();
        }

        label: for (int i = 0; i < n-m+1; i++) {   // ?
            for (int j = 0; j < n-m+1; j++) {   // ?
                for (int k = 0; k < m; k++) {
                    String s = a[i+k].substring(j, j+m);
                    if (!(s.equals(b[k]))) {
                        break;
                    }
                    if (k >= m-1) {
                        isAns = true;
                        break label;
                    }
                }
            }
        }
        
        System.out.println(isAns ? "Yes" : "No");
    }
}
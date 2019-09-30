import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }

        int r = 0;
        long sum = a[0];
        long res = 0;
        for(int l=0; l<n; l++) {
            while(r < n - 1) {
                if(sum + a[r+1] == (sum ^ a[r+1])) {
                    sum += a[r+1];
                    r++;
                } else {
                    break;
                }
            }
            res += r - l + 1;
            if(r == l && r < n - 1) {
                r++;
                sum += a[r];
            }
            sum -= a[l];
        }
        System.out.println(res);
    }

}
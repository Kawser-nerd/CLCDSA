import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] rate = new int[9];
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            for (int j = 8; j >= 0; j--) {
                if(r >= 400 * j){
                    rate[j]++;
                    break;
                }
            }
        }
        int var = 0;
        for (int i = 0; i < 8; i++) {
            if(rate[i] > 0) var++;
        }

        System.out.print(Math.max(var, 1) + " ");
        System.out.println(var + rate[8]);
        sc.close();
    }

}
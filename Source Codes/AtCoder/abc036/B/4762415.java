import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] input = new String[n];
        for (int i = 0; i < n; i++) {

            input[i] = sc.next();

        }
        for (int i = 0; i < n; i++) {
            for (int j = n; j >0;j--) {
                System.out.print(input[j-1].charAt(i));
            }
            System.out.println();
        }
    }
}
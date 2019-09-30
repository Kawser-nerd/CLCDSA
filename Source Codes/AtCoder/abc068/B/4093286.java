import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int maxCount = 0;
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            int num = i + 1;
            while (true) {
                if (num % 2 != 0) {
                    break;
                }
                num /= 2;
                count++;
            }
            if (i == 0 || count > maxCount) {
                maxCount = count;
                maxNum = i + 1;
            }
        }
        System.out.println(maxNum);
    }

}
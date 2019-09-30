import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        int zeroCount = 0;
        int oneCount = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '1') {
                zeroCount++;
            } else {
                oneCount++;
            }
        }

        int notDeletedCount = Math.abs(zeroCount - oneCount);
        int res = S.length() - notDeletedCount;

        System.out.println(res);
    }
}
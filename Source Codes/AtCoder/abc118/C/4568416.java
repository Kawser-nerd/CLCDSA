import java.text.SimpleDateFormat;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String,Integer> map = new HashMap<String,Integer>();
        String temp = sc.nextLine();

        int N = Integer.parseInt(temp);

        temp = sc.nextLine();
        String[] tempArr = temp.split(" ");
        int[] intArr = new int[N];

        for (int i = 0; i < N; i++) {
            intArr[i] = Integer.parseInt(tempArr[i]);
        }

        int previousGCD = 0;
        for (int j = 0; j < N; j++) {
            previousGCD = gcd(previousGCD,intArr[j]);

        }

        System.out.println(previousGCD);


    }

    static int gcd(int a, int b) {
        if (b > 0) {
            return gcd(b, a % b);
        } else {
            return a;
        }
    }

}
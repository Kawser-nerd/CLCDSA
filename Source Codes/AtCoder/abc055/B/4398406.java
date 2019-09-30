import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static boolean found = false;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long ret = 1;
        for (int i = 0; i < n; i++) {
            ret = (ret * (i + 1));
            ret = ret % 1000000007;
        }
        System.out.println(ret);


    }

}
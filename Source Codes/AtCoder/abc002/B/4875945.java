import java.util.Arrays;
import java.util.Collection;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String targets[] = {"a", "i", "u", "e", "o"};
        for (String target : targets
        ) {
            str = str.replaceAll(target, "");
        }
        System.out.println(str);

    }


    static String adjustValue(int value) {
        if (10 > value) {
            return "0" + value;
        } else {
            return value + "";
        }
    }
}
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] strings = s.split("\\+", 0);
        int count = 0;
        for (int i = 0 ; i < strings.length; i++) {
            if (!strings[i].contains("0")) {
                count++;
            }
        }
        System.out.println(count);
    }

}
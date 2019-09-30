import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        StringBuilder tmp = new StringBuilder();
        tmp.append(a);
        tmp.append(b);
        int number = Integer.parseInt(tmp.toString());

        for(int i = 0; i < 500; i++) {
            if (number == i*i) {
                System.out.println("Yes");
                System.exit(0);
            }
        }
        System.out.println("No");
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        
        for (char i = 'a'; i <= 'z'; i++) {
            if (s.indexOf(i) >= 0) {
                continue;
            } else {
                System.out.println(i);
                System.exit(0);
            }
        }
        System.out.println("None");
    }
}
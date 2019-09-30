import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = 0;
        int b = 0;
        for (int i = 0; i < 3; i++) {
            int value = input.nextInt();
            if (value == 5)
                a++;
            else if (value == 7)
                b++;
        }

        if (a == 2 && b == 1)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
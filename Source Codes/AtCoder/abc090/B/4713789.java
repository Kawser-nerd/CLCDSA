import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int count = 0;
        for(int i = a; i <= b; i++) {
            String reversedNumber = new StringBuilder(String.valueOf(i)).reverse().toString();
            if(String.valueOf(i).equals(reversedNumber)) count++;
        }
        System.out.println(count);
    }
}
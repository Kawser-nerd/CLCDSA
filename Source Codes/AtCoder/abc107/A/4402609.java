import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int i = Integer.parseInt(sc.next());
        System.out.println(N - i + 1);

    }
}
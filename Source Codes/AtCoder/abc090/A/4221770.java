import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] c1 = sc.next().split("");
        String[] c2 = sc.next().split("");
        String[] c3 = sc.next().split("");

        System.out.println(c1[0] + c2[1] + c3[2]);
    }

}
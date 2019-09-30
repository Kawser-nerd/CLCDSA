import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int nextInt () {return Integer.parseInt(sc.next());}

    public static void main(String[] args) {
        int X = nextInt();
        int Y = nextInt();

        System.out.println(X + Y / 2);
    }
}
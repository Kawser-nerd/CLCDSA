import java.util.*;

/**
 * Created by takaesumizuki on 2017/06/14.
 */
public class Main {
    void run() {
        Scanner sc = new Scanner(System.in);
        if(sc.nextInt() % 2 == 0) System.out.println("Blue");
        else System.out.println("Red");
    }

    public static void main(String[] args) {
        new Main().run();
    }

}
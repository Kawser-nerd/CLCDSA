import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int X = sc.nextInt();
        int t = sc.nextInt();   
        System.out.println((X - t > 0)? X - t : 0);
    }
}
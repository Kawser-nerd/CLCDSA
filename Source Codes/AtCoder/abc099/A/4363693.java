import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();

        System.out.println(N < 1000 ? "ABC" : "ABD");
    }
}
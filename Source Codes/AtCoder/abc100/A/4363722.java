import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        System.out.println(A <= 8 && B <= 8 ? "Yay!" : ":(");
    }
}
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        char X = sc.next().charAt(0);
        char Y = sc.next().charAt(0);
        
        int num = X - Y;
        System.out.println(num < 0 ? "<" : (num > 0) ? ">" : "=");
    }
}
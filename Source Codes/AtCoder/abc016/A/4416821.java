import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        if(n%m==0)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
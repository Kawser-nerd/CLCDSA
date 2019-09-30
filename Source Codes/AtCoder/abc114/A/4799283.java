import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        if (x == 3 || x == 5 || x == 7) {
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        sc.close();
    }
}
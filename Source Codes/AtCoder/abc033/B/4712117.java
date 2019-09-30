import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int sum = 0;
        int max = 0;
        String name = "atcoder";
        
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            int p = sc.nextInt();
            
            sum += p;
            if (max < p) {
                max = p;
                name = s;
            }
        }
        
        if (sum/2 >= max) {
            name = "atcoder";
        }
        
        System.out.println(name);
    }
}
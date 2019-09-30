import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n,m,g=0;
        for(int i=0;i<3;i++){
            n = sc.nextInt();
            m = sc.nextInt();
            g += n*m/10;
        }
        System.out.println(g);
    }
}
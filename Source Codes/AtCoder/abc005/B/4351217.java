import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(),x,g=101;
        for(int i=0;i<n;i++){
            x = sc.nextInt();
            g = Math.min(x,g);
        }
        System.out.println(g);
    }
}
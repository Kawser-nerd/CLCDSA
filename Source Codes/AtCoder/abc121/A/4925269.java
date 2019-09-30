import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int H,W,h,w;
        H=s.nextInt();
        W=s.nextInt();
        h=s.nextInt();
        w=s.nextInt();
        
        System.out.println((W-w)*(H-h));

    }  
}
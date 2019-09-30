import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class SnapperChain {
    private boolean solve(int n, int k) {
        if (((k + 1) % (1<<n)) == 0)
            return true;
        else
            return false;
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(System.in);
        int count = s.nextInt();
        SnapperChain instance = new SnapperChain();
        for (int i=0; i<count; ++i) {
            int n = s.nextInt();
            int k = s.nextInt();
            System.out.println("Case #" + (i+1) + ": " + (instance.solve(n, k)?"ON":"OFF"));
        }
    }
}

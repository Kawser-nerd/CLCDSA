import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int i,j;
        char[] c = new char[16];
        for(i=15;i>=0;i--)
            c[i] = sc.next().charAt(0);
        for(i=1;i<=16;i++){
            if(i%4==0)
                System.out.println(c[i-1]+" ");
            else
                System.out.print(c[i-1]+" ");
        }
    }
}
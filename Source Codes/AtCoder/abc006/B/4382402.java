import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a=0,b=0,c=1,n=sc.nextInt(),w;
        for(int i=1;i<n;i++){
            w = c;
            c = (a+b+c)%10007;
            a = b;
            b = w;
        }
        System.out.println(a);
    }
}
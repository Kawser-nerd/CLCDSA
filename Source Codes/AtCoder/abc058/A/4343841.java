import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
    
        if((b -a) == (c - b)){
            System.out.print("YES");
        }else{
            System.out.print("NO");
        }
    }
}
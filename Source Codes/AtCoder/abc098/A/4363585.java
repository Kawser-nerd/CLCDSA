import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        int add = A + B;
        int sub = A - B;
        int mul = A * B; 
        int max = 0;
        
        if(add >= sub && add >= mul) max = add;
        if(sub >= add && sub >= mul) max = sub;
        if(mul >= add && mul >= sub) max = mul;

        System.out.println(max);
    }
}
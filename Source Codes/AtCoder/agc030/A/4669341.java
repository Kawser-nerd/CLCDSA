import java.util.*;

public class Main{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        String Astr, Bstr, Cstr;
        Astr = sc.next();
        Bstr = sc.next();
        Cstr = sc.next();
        int A = Integer.parseInt(Astr);
        int B = Integer.parseInt(Bstr);
        int C = Integer.parseInt(Cstr);

        int ans = 0;
        if(A + B >= C){
            ans = B + C;
        }else{
            ans = A + 2 * B + 1;
        }

        System.out.println(ans);
        
    }
}
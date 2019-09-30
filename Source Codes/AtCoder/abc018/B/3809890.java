import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        int n = scan.nextInt();
        for(int i = 0;i<n;i++){
            int a = scan.nextInt()-1;
            int b = scan.nextInt();
            StringBuffer sb = new StringBuffer();
            StringBuffer sb2 = new StringBuffer();
            sb.append(s.substring(0,a));
            sb2.append(s.substring(a,b)).reverse();
            sb.append(sb2);
            sb.append(s.substring(b));
            s = sb.toString();
        }
        System.out.println(s);
    }
}
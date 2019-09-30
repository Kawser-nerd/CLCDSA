import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	String str = sc.next();
	if(str.charAt(str.length()-1) =='T') {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
    }
}
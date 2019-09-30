import java.util.Scanner;
 
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        s = s.replace("ch", "");
        if(s.matches("[oku]*")){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
}
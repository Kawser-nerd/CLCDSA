import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String b = sc.nextLine();
        String str = "";
        switch(b){
            case "A":
                str = "T";
            break;
            case "T":
                str = "A";
            break;
            case "C":
                str = "G";
            break;
            case "G":
                str = "C";
            break;
            default:
            break;
        }
        System.out.println(str);
    }
}
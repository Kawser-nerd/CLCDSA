import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String date = sc.next();
        String[] info = date.split("/");
        int year = Integer.parseInt(info[0]),
        month = Integer.parseInt(info[1]);
        if(year < 2019 || year == 2019 && month < 5){
            System.out.println("Heisei");
        } else {
            System.out.println("TBD");
        }
    }
}
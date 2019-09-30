import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt(), y1 = sc.nextInt(),
            x2 = sc.nextInt(), y2 = sc.nextInt();
        int x = x2 - x1, y = y2 - y1;
        int x3 = x2 - y, y3 = y2 + x,
            x4 = x1 - y, y4 = y1 + x;
        System.out.println(x3 + " " + y3 + " " +
                            x4 + " " + y4);
    }
}
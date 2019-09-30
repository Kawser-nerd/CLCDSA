import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        System.out.println(x/11*2+(x%11>6?2:(x%11==0?0:1)));
    }

}
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=0;
        for(int i=0;i<3;i++){
            output+=sc.nextInt()*sc.nextInt()/10;
        }
        System.out.println(output);
    }

}
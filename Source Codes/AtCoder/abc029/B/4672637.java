import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=0;
        for(int i=0;i<12;i++){
            if(sc.next().contains("r")){
                output++;
            }
        }
        System.out.println(output);
    }
}
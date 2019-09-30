import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        char a = sc.next().charAt(0);
        char b = sc.next().charAt(0);
        char TopCoDeer = b;
        
       //a == 'H'??? TopCoDeer = b?????????a == 'D'??????
        if(a == 'D'){
            if(b == 'H'){
                TopCoDeer = 'D';
            }else{
                TopCoDeer = 'H';
            }
        }
        System.out.print(TopCoDeer);
    }
}
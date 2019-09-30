import java.util.*;

public class Main {


    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int s    = scan.nextInt();


        if(s == 4 || s == 2 || s == 1){
            System.out.println(4);
            return;
        }


        int input=s;
        int output=0;
        int i = 1;
        while(true){

            i++;

            if(input % 2 == 0 ){

                output = input/2;

            }else{

                output = input*3 + 1;

            }

            if(output == 4){
                System.out.println(i + 3);
                return;
            }

            input = output;
        }
    }
}
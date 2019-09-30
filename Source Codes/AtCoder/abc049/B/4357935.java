import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int h = scan.nextInt();
        int w = scan.nextInt();
        List<String> list = new ArrayList<String>();
        for(int i = 0; i < h; i++){
            String nextWord = scan.next();
            list.add(nextWord);
        }

        for(int i = 0; i < h; i++){
            System.out.println(list.get(i) + "\n" + list.get(i));
        }
    }
}
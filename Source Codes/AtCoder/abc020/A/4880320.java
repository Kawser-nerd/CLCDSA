import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String answer = null;
        ArrayList <Integer> b = new ArrayList<>();
        for(int i = 0;i<1;i++){
            b.add(Integer.parseInt(scan.next()));
        }
        if(b.get(0)==1){
            answer = "ABC";
        }else{
            answer = "chokudai";
        }

        PrintWriter out = new PrintWriter(System.out);
        out.println(answer);
        out.flush();
        scan.close();
    }
}
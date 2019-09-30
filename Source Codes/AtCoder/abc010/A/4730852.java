import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.String;

public class Main {
    public static void main(String args[]){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            String str = br.readLine();

            System.out.println(str + "pp");

        }catch(IOException e){
            System.out.println("Exception :" + e);
        }
    }
}
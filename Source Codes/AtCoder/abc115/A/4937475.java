import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int D = Integer.parseInt(bf.readLine());
        String str;
        switch(D){            
            case 25:
                str = "Christmas";
                break;
            case 24:
                str = "Christmas Eve";
                break;
            case 23:
                str = "Christmas Eve Eve";
                break;
            default:
                str = "Christmas Eve Eve Eve";
        } 
        System.out.println(str);
    }
}
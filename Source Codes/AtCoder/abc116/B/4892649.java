import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int s = Integer.valueOf(bf.readLine()),
            m = 1;
        Set<Integer> number = new HashSet<>();
        while(true){
            if(!number.add(s)){
                break;
            }
            if(s%2 > 0){
                s = 3*s + 1;
            } else{
                s /= 2;
            }
            m++;
        }        
        System.out.println(m);
    }
}
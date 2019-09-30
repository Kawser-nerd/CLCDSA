import java.io.*;

public class Main {

    static final int N = 10000;

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long x=Long.parseLong(br.readLine());
        long sum=x/11;
        long temp=x%11;
        if(temp!=0){
            System.out.println((temp>6) ? sum*2+2:sum*2+1);
        }else{
            System.out.println(sum*2);
        }
    }
    
}
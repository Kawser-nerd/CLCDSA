import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s=br.readLine(), t=br.readLine();
        if(s.length()>t.length())out.println(s);
        else out.println(t);
        out.flush();
    }
}
class Dice{
    private int[] memo=new int[6];
    private static final String equalmove="NNNNWNNNWNNNENNNENNNWNNN";
    public Dice(int[] in){
        Set(in[0],in[1],in[2],in[3],in[4],in[5]);
    }
    private void Set(int a,int b,int c,int d,int e,int f){
        memo[0]=a;memo[1]=b;memo[2]=c;memo[3]=d;memo[4]=e;memo[5]=f;
    }
    public void move(char c){
        switch(c){
            case 'W':
                Set(memo[2],memo[1],memo[5],memo[0],memo[4],memo[3]);
                break;
            case 'N':
                Set(memo[1],memo[5],memo[2],memo[3],memo[0],memo[4]);
                break;
            case 'S':
                Set(memo[4],memo[0],memo[2],memo[3],memo[5],memo[1]);
                break;
            case 'E':
                Set(memo[3],memo[1],memo[0],memo[5],memo[4],memo[2]);
                break;
            default:
                System.out.println("error");
        }
    }
    public int Get(int i){
        return memo[i];
    }
    public boolean isequal(Dice D2){
        if(D2==this)return true;
        for(int i=0;i<equalmove.length();i++){
            this.move(equalmove.charAt(i));
            boolean flag=true;
            for(int j=0;j<6;j++){
                if(this.Get(j)!=D2.Get(j)){
                    flag=false;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
    }
}
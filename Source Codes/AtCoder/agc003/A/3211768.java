import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int a[]=new int[4],ns=0,we=0;
        String s=new String();
        s=sc.next();
        sc.close();
        for(int i=0;i<s.length();++i){
            if(s.charAt(i)=='N')++a[0];
            else if(s.charAt(i)=='W')++a[1];
            else if(s.charAt(i)=='S')++a[2];
            else ++a[3];
        }
        for(int i=0;i<4;i+=2)if(a[i]>0)++ns;
        for(int i=1;i<4;i+=2)if(a[i]>0)++we;
        System.out.print(ns%2>0||we%2>0?"No":"Yes");
    }
}
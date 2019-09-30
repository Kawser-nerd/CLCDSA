import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.next();
        char[] c=new char[str.length()];
        char[] tmp=new char[str.length()];
        for(int i=0;i<c.length;i++){
            c[i]=str.charAt(i);
        }
        int n=sc.nextInt();
        int tmpL;
        int tmpR;
        for(int i=0;i<n;i++){
            tmpL=sc.nextInt()-1;
            tmpR=sc.nextInt()-1;
            for(int j=0;j<tmpR-tmpL+1;j++){
                tmp[j]=c[tmpL+j];
            }
            for(int j=0;j<tmpR-tmpL+1;j++){
                c[tmpL+j]=tmp[tmpR-tmpL-j];
            }
        }
        for(char a:c){
            System.out.print(a);
        }
        System.out.println("");
    }

}
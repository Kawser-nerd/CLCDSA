import java.util.*;
import static java.lang.System.in;
import static java.lang.System.out;

public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(in);
	String[] input=sc.nextLine().split(" ",0);
	int[] lh=new int[2];
	lh[0]=Integer.parseInt(input[0]);
	lh[1]=Integer.parseInt(input[1]);
	int num=sc.nextInt();
	int[] st=new int[num];
	for(int i=0;i<num;i++)
	    st[i]=sc.nextInt();
	for(int i=0;i<num;i++)
	    if(st[i]<lh[0])out.println(lh[0]-st[i]);
	    else if(st[i]>lh[1])out.println(-1);
	    else out.println("0");
	
    }
}
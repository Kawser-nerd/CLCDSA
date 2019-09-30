import java.util.*;
import static java.lang.System.in;
import static java.lang.System.out;

public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(in);
	int counter=0;
	for(int i=0;i<12;i++){
	    String str=sc.nextLine();
	    if(str.contains("r"))counter++;
	}
	out.println(counter);
    }
}
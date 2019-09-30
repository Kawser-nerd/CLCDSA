import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
Scanner scan=new Scanner(System.in);
String str=scan.next();
int a=scan.nextInt();
Set<String> list=new HashSet<>();
for(int i=0;i<=str.length()-a;i++) {
	String str2=str.substring(i,i+a);
	list.add(str2);
}
System.out.println(list.size());
	}

}
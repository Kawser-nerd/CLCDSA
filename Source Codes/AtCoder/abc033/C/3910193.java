import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String[] b = a.split("\\+");
		int count = 0;
		for(String e:b){
			if(!e.contains("0")){
				count++;
			}
		}
		System.out.println(count);
	}
}
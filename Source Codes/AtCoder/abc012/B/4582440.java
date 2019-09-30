import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);

			long second = sc.nextLong();
			
			long date = second/3600;
			String d = (String.format("%02d", date));
			
			long minute = (second%3600)/60;
			String m = (String.format("%02d", minute));
			
			long sec = ((second%360))%60;
			String s = (String.format("%02d", sec));
			
			System.out.println(d+":"+m+":"+s);
			
		}
}
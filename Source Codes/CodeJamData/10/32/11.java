package round_1B_2010;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class LoadTestingR {
	public static void main(String[] args) {
		
		Scanner reader=new Scanner(System.in);
		try {
			FileWriter writer=new FileWriter(new File("D:/ltrout_large.txt"));
			int t=reader.nextInt();
			for(int cc=1;cc<=t;++cc){
				
				long l=reader.nextInt();
				long p=reader.nextInt();
				
				int c=reader.nextInt();
				
				int sum=0;
				long now=p;
				if(l*c>=p){
					writer.write("Case #"+cc+": 0\r\n");
				}
				else{
					while(true){
						sum++;
						now=(now+c-1)/c;
						if(l*c>=now)
							break;
					}
					int result=(int)Math.ceil(Math.log(sum+1)/Math.log(2));
					writer.write("Case #"+cc+": "+result+"\r\n");
				}
				writer.flush();
			}
			writer.close();
		}
		catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	
}

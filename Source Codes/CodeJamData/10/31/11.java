package round_1B_2010;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class RopeIntranet {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner reader=new Scanner(System.in);
		
		try {
			FileWriter writer=new FileWriter(new File("D:/RIout1.txt"));
			int t=reader.nextInt();
			for(int cc=1;cc<=t;++cc){
				int n=reader.nextInt();
				line[] lines=new line[n];
				for(int i=0;i<n;++i){
					lines[i]=new line();
					lines[i].a=reader.nextInt();
					lines[i].b=reader.nextInt();
				}
				int result=0;
				for(int i=0;i<n;++i){
					for(int j=i+1;j<n;++j){
						if((lines[i].a-lines[j].a)*(lines[i].b-lines[j].b)<0){
							result++;
						}
						
					}
				}
				writer.append("Case #"+cc+": "+result+"\r\n");
				writer.flush();
			}
			writer.close();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}
class line{
	int a;
	int b;
	
}
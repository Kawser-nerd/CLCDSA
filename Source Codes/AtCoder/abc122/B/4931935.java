import java.io.IOException;
public class Main {
	public static void main(String[] args) throws IOException {
		char moji[]=new char[11];
		int count[]=new int[11];
		for(int i=0;i<10;i++) {
			moji[i]=(char)System.in.read();
			if(moji[i]=='\n') {
				break;
			}
		}
		for(int i=0,j=0;i<moji.length;i++,j++) {

			while(moji[i]=='A'||moji[i]=='C'||moji[i]=='G'||moji[i]=='T') {
				count[j]++;
					i++;
			}
		}
		int max=0;
		for(int i=0;i<count.length;i++) {
			if(max<count[i]) {
				max=count[i];
			}
		}
		System.out.println(max);
	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		String[] strArray = br.readLine().split(" ");
		int caseNum = Integer.parseInt(strArray[0]);
		int listenedCdNum = Integer.parseInt(strArray[1]);
		int listenDisk = 0;
		int[] cdCase = new int[caseNum];
		for(int i=1;i<=caseNum;i++) {
			cdCase[i-1] = i;
		}
		for(int i=0;i<listenedCdNum;i++) {
			int disk = Integer.parseInt(br.readLine());
			for(int j=0;j<caseNum;j++) {
				if(cdCase[j] == disk) {
					cdCase[j] = listenDisk;
					listenDisk= disk;
				}
			}
		}
		for(int diskNum : cdCase) {
			System.out.println(diskNum);
		}
	}
}
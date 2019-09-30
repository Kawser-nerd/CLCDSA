import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("B-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        PriorityQueue<Integer> queue1=new PriorityQueue<Integer>();
        PriorityQueue<Integer> queue2=new PriorityQueue<Integer>();
        for(int t=1;t<=T;t++){
        	queue1.clear();
        	queue2.clear();
        	s=new StringTokenizer(br.readLine().trim());
        	int Ac=Integer.parseInt(s.nextToken());
        	int Aj=Integer.parseInt(s.nextToken());
        	int sum=Ac+Aj;
        	int[][] arr=new int[sum][3];
        	int Timec=0;
        	int Timej=0;
        	for(int i=0;i<Ac;i++){
        		s=new StringTokenizer(br.readLine().trim());
        		arr[i][0]=Integer.parseInt(s.nextToken());
        		arr[i][1]=Integer.parseInt(s.nextToken());
        		arr[i][2]=1;
        		Timec+=(arr[i][1]-arr[i][0]);
        	}
        	for(int i=0;i<Aj;i++){
        		s=new StringTokenizer(br.readLine().trim());
        		arr[i+Ac][0]=Integer.parseInt(s.nextToken());
        		arr[i+Ac][1]=Integer.parseInt(s.nextToken());
        		arr[i+Ac][2]=2;
        		Timej+=(arr[i+Ac][1]-arr[i+Ac][0]);
        	}
        	Arrays.sort(arr,new Comparator<int[]>(){
        		public int compare(int a[],int b[]){
        			return Integer.compare(a[0], b[0]);
        		}
        	});
        	int change=0;
        	int sum1=0;
        	int o1=0;
        	int sum2=0;
        	int o2=0;
        	for(int i=0;i<sum;i++){
        		if(arr[i][2]!=arr[(i+1)%sum][2]){
        			change++;
        		}else{
        			if(arr[i][2]==1){
        				sum1+=((arr[(i+1)%sum][0]-arr[i][1]+1440)%1440);
        				queue1.add((arr[(i+1)%sum][0]-arr[i][1]+1440)%1440);
        				o1++;
        			}else{
        				sum2+=((arr[(i+1)%sum][0]-arr[i][1]+1440)%1440);
        				queue2.add((arr[(i+1)%sum][0]-arr[i][1]+1440)%1440);
        				o2++;
        			}        			
        		}
        	}
        	if(Timec+sum1>720){
        		int temp=0;
        		while(!queue1.isEmpty()){
        			int k=queue1.poll();
        			temp+=k;
        			if(temp+Timec<=720){
        				o1--;
        			}else{
        				break;
        			}
        		}
        		change+=(o1*2);
        	}else if(Timej+sum2>720){
        		int temp=0;
        		while(!queue2.isEmpty()){
        			int k=queue2.poll();
        			temp+=k;
        			if(temp+Timej<=720){
        				o2--;
        			}else{
        				break;
        			}
        		}
        		change+=(o2*2);
        	}        	
        	bw.write("Case #"+t+": ");
        	bw.write(change+"\n");
        }
        br.close();
        bw.close();
        return;
    }
}
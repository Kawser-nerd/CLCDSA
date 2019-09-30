import java.util.*;
import java.io.*;
public class Main{
public static void main(String [] args)throws Exception{
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = new StringTokenizer(br.readLine());
  int xs = Integer.parseInt(st.nextToken());
  int ys = Integer.parseInt(st.nextToken());
  int xt = Integer.parseInt(st.nextToken());
  int yt = Integer.parseInt(st.nextToken());
  int n = Integer.parseInt(br.readLine());
  int circles[][] = new int[n + 2][3];
  circles[0][0] = xs;circles[0][1] = ys;
  circles[n + 1][0] = xt;circles[n + 1][1] = yt;
  for(int i = 1;i <= n;i++){
  	st = new StringTokenizer(br.readLine());
  	circles[i][0] = Integer.parseInt(st.nextToken());
  	circles[i][1] = Integer.parseInt(st.nextToken());
  	circles[i][2] = Integer.parseInt(st.nextToken());
}
   double dist[][] = new double[n + 2][n + 2];
   for(int i = 0;i <= n + 1;i++){
   	for(int j = i + 1;j <= n + 1;j++){
   		double temp = Math.sqrt((circles[i][0] - circles[j][0])*1.0*(circles[i][0] - circles[j][0]) +
   		       (circles[i][1] - circles[j][1])*1.0*(circles[i][1] - circles[j][1]));
   		if(temp < circles[i][2] + circles[j][2])temp = 0;
   		else temp -= circles[i][2] + circles[j][2];
   		dist[i][j] = dist[j][i] = temp;
   	}
   }
   PriorityQueue<Node>pq = new PriorityQueue<Node>();
   pq.add(new Node(0,0));
   boolean visited[] = new boolean[n + 2];
   while(!pq.isEmpty()){
     Node temp = pq.remove();
     if(visited[temp.idx])continue;
     if(temp.idx == n + 1){
     	System.out.println(temp.dist);
     	return;
     }
     visited[temp.idx] = true;
     for(int i = 0;i <= n + 1;i++){
     	if(visited[i])continue;
     	pq.add(new Node(i,temp.dist + dist[temp.idx][i]));
     }
   }
}
static class Node implements Comparable<Node>{
	int idx;
	double dist;
	Node(int idx,double dist){
		this.idx = idx;
		this.dist = dist;
	}
	public int compareTo(Node other){
		return Double.compare(dist,other.dist);
	}
}
}
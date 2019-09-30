import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Coordinate[] coordinate = new Coordinate[n];
		for(int i = 0;i < n;i++){
			coordinate[i] = new Coordinate(sc.nextInt(), sc.nextInt(),sc.nextInt());
		}

		double maxX = 0;
		double maxY = 0;
		for(int i = 0;i < n-1;i++){
			double x1 = coordinate[i].x;
			double y1 = coordinate[i].y;
			double cost1 = coordinate[i].cost;
			for(int j = i;j < n;j++){
				double x2 = coordinate[j].x;
				double y2 = coordinate[j].y;
				double cost2 = coordinate[j].cost;
				double midX = Math.abs(x1-x2)*cost1/(cost1+cost2)*cost2;
				double midY = Math.abs(y1-y2)*cost1/(cost1+cost2)*cost2;
				maxX = Math.max(maxX, midX);
				maxY = Math.max(maxY, midY);
			}
		}

		System.out.println(Math.max(maxX, maxY));
	}
}

class Coordinate{
	double x;
	double y;
	double cost;
	Coordinate(double x, double y, double cost){
		this.x = x;
		this.y = y;
		this.cost = cost;
	}
}
import java.util.Scanner;

public class Mass {

	public static int N;

	public static Fly [] flies;

	public static Fly mass;

	public static void main (String [] args) {
		
		Scanner S;
		double nx, ny, nz, r, rn, rd, px, py, pz, v;
		int T, i, caso;
		
		S = new Scanner (System.in);
		T = S.nextInt();
		caso = 1;
		while (T-- > 0) {
			N = S.nextInt();
			flies = new Fly [N];
			mass = new Fly (0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			nx = ny = nz = 0.0;
			for (i=0 ; i<N ; i++) {
				flies[i] = new Fly ((double)S.nextInt(), (double)S.nextInt(), (double)S.nextInt(), (double)S.nextInt(), (double)S.nextInt(), (double)S.nextInt());
				mass.x += flies[i].x;
				mass.y += flies[i].y;
				mass.z += flies[i].z;
				nx += flies[i].x + flies[i].vx;
				ny += flies[i].y + flies[i].vy;
				nz += flies[i].z + flies[i].vz;
			}
			mass.x /= (double)N;
			mass.y /= (double)N;
			mass.z /= (double)N;
			nx /= (double)N;
			ny /= (double)N;
			nz /= (double)N;
			mass.vx = nx - mass.x;
			mass.vy = ny - mass.y;
			mass.vz = nz - mass.z;
			//System.out.println("\nmass = (" + mass.x + " , " + mass.y + " , " + mass.z + ") , (" + mass.vx + " , " + mass.vy + " , " + mass.vz  + ")");
			
			//rn = mass.x*nx + mass.y*ny + mass.z*nz;
			rn = mass.x*(mass.x-nx) + mass.y*(mass.y-ny) + mass.z*(mass.z-nz);
			rd = (mass.x-nx)*(mass.x-nx) + (mass.y-ny)*(mass.y-ny) + (mass.z-nz)*(mass.z-nz);
			r = rn / rd;
			v = mass.vx*mass.vx + mass.vy*mass.vy + mass.vz*mass.vz;
			
			//System.out.println("\nr = " + r+" , rn = " + rn + " , rd = " + rd + "\n");
			if (r<0 || v==0) {
				rn = Math.sqrt(mass.x*mass.x + mass.y*mass.y + mass.z*mass.z);
				System.out.println(String.format("Case #" + (caso++) + ": %.8f 0.00000000", rn).replaceAll(",", "."));
			} else {
				px = mass.x + r*mass.vx;
				py = mass.y + r*mass.vy;
				pz = mass.z + r*mass.vz;
				rn = Math.sqrt(px*px + py*py + pz*pz);
				System.out.println(String.format("Case #" + (caso++) + ": %.8f %.8f", rn, r).replaceAll(",", "."));
			}
		}
		
	}

}

class Fly {

	double x, y, z, vx, vy, vz;

	public Fly (double x, double y, double z, double vx, double vy, double vz) {
		
		this.x = x;
		this.y = y;
		this.z = z;
		this.vx = vx;
		this.vy = vy;
		this.vz = vz;
		
	}

}